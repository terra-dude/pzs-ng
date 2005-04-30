/*
 * zsconfig.defaults.h - ZipScript-C default config file
 * 
 * DO NOT EDIT THIS FILE!!
 * 
 * This file contains all settings, and it's default values. You should not edit
 * this file, but instead copy the settings you need into zsconfig.h, which
 * will override the default settings found in here. So do not remove or
 * change anything in this file!! A complete list of settings, with comments
 * can be found in README.ZSCONFIG
 */


/*
 * General Settings
 * ================
 */

/*
 * These should be changed to match your glftpd installation. All pathnames
 * must end with a slash ( / ) All paths are chroot'ed.
 * log - /path/name of your glftpd.log
 * storage - place where the zipscript stores racedata.  Should not be
 * accessible to your site's users.
 * gl_userfiles - path to glftpd's dir with userfiles.
 * dupepath - /path/name to glftpd's dupefile.
 * gl_section - names of sections defined in glftpd.conf
 */
#ifndef sitepath_dir
#define sitepath_dir	"/site/"
#endif
#ifndef log
#define log		"/ftp-data/logs/glftpd.log"
#endif
#ifndef storage
#define storage		"/ftp-data/pzs-ng/"
#endif
#ifndef gl_userfiles
#define gl_userfiles	"/ftp-data/users/"
#endif
#ifndef dupepath
#define dupepath	"/ftp-data/logs/dupefile"
#endif
#ifndef banned_filelist
#define banned_filelist	"/ftp-data/misc/banned_filelist.txt"
#endif
#ifndef gl_sections
#define gl_sections	"DEFAULT"
#endif


/*
 * Per default, announcing is disabled everywhere, use zip/sfv paths to
 * enable announces and private paths to disable. Don't be lazy! Be specific!
 * And remember - pathnames are case sensitive. All pathnames must end with a
 * slash ( / ) All paths are chroot'ed.
 * group_dirs - paths where announcing should be turned off.
 * zip_dirs - paths where zipfiles normally are uploaded.
 * sfv_dirs - paths where sfv-releases normally are uploaded.
 * nocheck_dirs - paths where no checking of files occur at all. This overrides zip/sfv/group-dirs.
 * audio_nocheck_dirs - paths where mp3 files are not checked for genre, bitrate etc.
 * allowed_types_exemption_dirs - paths where certain files are not checked/denied if no sfv-file is uploaded.
 * check_for_missing_nfo_dirs - these dirs will be checked for missing nfo's after a release is complete.
 * check_for_missing_nfo_filetypes - these filetypes will be checked for missing nfo's after a release is complete.
 *  Please note that the list of filetypes is defined (rar,other,audio,video,zip)
 */

#ifndef group_dirs
#define group_dirs			"/site/groups/"
#endif
#ifndef zip_dirs
#define zip_dirs			"/site/test/ /site/incoming/0day/"
#endif
#ifndef sfv_dirs
#define sfv_dirs			"/site/test/ /site/incoming/mp3/ /site/incoming/games/ /site/incoming/apps/ /site/incoming/musicvideos/ /site/incoming/requests/"
#endif
#ifndef nocheck_dirs
#define nocheck_dirs			"/site/private/"
#endif
#ifndef speedtest_dirs
#define speedtest_dirs			"/site/speedtest/"
#endif
#ifndef noforce_sfv_first_dirs
#define noforce_sfv_first_dirs		"/site/incoming/requests/"
#endif
#ifndef use_partial_on_noforce
#define use_partial_on_noforce		FALSE
#endif
#ifndef rescan_nocheck_dirs_allowed
#define rescan_nocheck_dirs_allowed	TRUE
#endif
#ifndef audio_nocheck_dirs
#define audio_nocheck_dirs		"/site/groups/ /site/incoming/requests/"
#endif
#ifndef allowed_types_exemption_dirs
#define allowed_types_exemption_dirs	"/site/incoming/musicvideos/"
#endif
#ifndef check_for_missing_nfo_dirs
#define check_for_missing_nfo_dirs	"/site/incoming/games/ /site/incoming/apps/"
#endif
#ifndef check_for_missing_nfo_filetypes
#define check_for_missing_nfo_filetypes	DISABLED
#endif
#ifndef create_incomplete_links_in_group_dirs
#define create_incomplete_links_in_group_dirs	TRUE
#endif
/*
 * Normally rar files are allowed in zip dirs and vice versa. Setting the
 * strict mode on refuses any such mismatch.
 */
#ifndef strict_path_match
#define strict_path_match		FALSE
#endif

/*
 * Normally files marked as bad are deleted. You can change this by setting the
 * following value to TRUE - instead of the file being deleted, it will be renamed
 * <filename>.bad. Bad files are ignored on rescan.
 */
#ifndef mark_file_as_bad
#define mark_file_as_bad		FALSE
#endif

/*
 * Broken transfers may be a problem on some sites. Glftpd2 and pzs-ng allow you
 * to resume such files by setting this to TRUE.
 */
#ifndef allow_file_resume
#define allow_file_resume		FALSE
#endif

/*
 * Whenever a bad file is encountered, you can add a delay for the user between
 * 1 and 1000 seconds. Put the number of seconds glftpd should sleep. Setting
 * this to 0 ( or >1000) will disable this feature.
 */
#ifndef sleep_on_bad
#define sleep_on_bad			0
#endif

#ifndef test_for_password
#define test_for_password		TRUE
#endif
#ifndef extract_nfo
#define extract_nfo			TRUE
#endif
#ifndef deny_nfo_upload_in_zip
#define deny_nfo_upload_in_zip		FALSE
#endif

/*
 * Certain files are needed to change uid/gid to real names. All paths are
 * chroot'ed.
 * GROUPFILE - /path/name of glftpd's group file
 * PASSWDFILE - /path/name of glftpd's passwd file
 */
#ifndef GROUPFILE
#define GROUPFILE	"/etc/group"
#endif
#ifndef PASSWDFILE
#define PASSWDFILE	"/etc/passwd"
#endif

/*
 * You can use a cookie for sitename, short version. This will be used in
 * incompletebars, completebars etc.
 */
#ifndef short_sitename
#define short_sitename	"NG"
#endif

/*
 * Here is a list of subdirs (not case sensitive). Use ? as wildcard.
 */
#ifndef subdir_list
#define subdir_list	"cd??,disc??,disk??,dvd??,extra?,sub?,subtitle?,vobsub?,sample?,subpack?"
#endif

/*
 * Directories for cleanup to check for broken incomplete files. Used by the
 * cleanup binary (which should be run in crontab) to remove stale links. Use
 * %m for month and %d for day in dated dirs. All paths are chroot'ed.
 * days_back_cleanup - how many days should cleanup go? 1=today, 0=disabled.
 * cleanupdirs - paths to be checked for broken links - these are not recursive.
 * cleanupdirs_dated - path with dated dirs.
 * This has also effect on the incomplete-list.sh script added in the archive.
 * If you use this on your bot, make sure to fill in correct paths.
 */

#ifndef days_back_cleanup
#define days_back_cleanup	2
#endif
#ifndef cleanupdirs
#define cleanupdirs		"/site/test/ /site/incoming/games/ /site/incoming/apps/ /site/incoming/musicvideos/"
#endif
#ifndef cleanupdirs_dated
#define cleanupdirs_dated	"/site/incoming/0day/%m%d/ /site/incoming/mp3/%m%d/"
#endif
#ifndef always_scan_audio_syms
#define always_scan_audio_syms	FALSE
#endif

/*
 * Write .message file on complete in group_dirs?
 */
#ifndef write_complete_message_in_group_dirs
#define write_complete_message_in_group_dirs	TRUE
#endif

/*
 * Hide name of uploaders in the .message-file in group-dirs? Setting this to
 * TRUE will convert the username to the groupname of the user.
 */
#ifndef hide_group_uploaders
#define hide_group_uploaders	TRUE
#endif
#ifndef hide_gname
#define hide_gname		""
#endif
#ifndef hide_uname
#define hide_uname		""
#endif


/*
 * You may also choose a custom message to be put into the .message file in
 * the group dirs. Define your message here, or put DISABLED to disable.
 */
#ifndef custom_group_dirs_complete_message
#define custom_group_dirs_complete_message	"... Looks like this is a pre. :)"
#endif

/*
 * Creates a zero-byte file for every non-existing file defined in sfv?
 */
#ifndef create_missing_files
#define create_missing_files	TRUE
#endif

/*
 * Defines type of status bar (see below for the format of the status bar)
 * 0 = file
 * 1 = directory
 */
#ifndef status_bar_type
#define status_bar_type		1
#endif

/*
 * Defines type of incomplete pointer (see below for the format of the
 * incomplete pointer)
 * 0 = file
 * 1 = symbolic link
 */
#ifndef incompleteislink
#define incompleteislink	1
#endif

/*
 * Defines symbolic link type on incomplete and no-nfo indicators.
 * 0 = absolute path
 * 1 = relative path
 */
#ifndef userellink
#define userellink		1
#endif

/*
 * If file has suid bit set, program changes uid and gid to these (0 leaves
 * option uncompiled)
 */
#ifndef program_uid
#define program_uid		0
#endif
#ifndef program_gid
#define program_gid		0
#endif

/*
 * These file types are allowed without any checks
 */
#ifndef allowed_types
#define allowed_types		"jpg,cue,m3u,mpg,mpeg,avi,txt,mov,vob"
#endif

/*
 * These file types are ignored from sfv NOTE: , at the beginning ignores all
 * files without extensions
 */
#ifndef ignored_types
#define ignored_types		",diz,debug,message,imdb,html,url"
#endif

/*
 * Should we allow files uploaded that is not in the sfv? This is only valid
 * on upload (not rescan etc), and is normally not used.
 */
#ifndef allow_files_not_in_sfv
#define allow_files_not_in_sfv	FALSE
#endif

/*
 * Whenever "bad" entries are found in the sfv, they are usually ignored.
 * Setting this settingto true will mark the entire sfv as bad if such entries
 * are found, forcing the user to upload a valid sfv file.
 */
#ifndef strict_sfv_check
#define strict_sfv_check	FALSE
#endif

/*
 * Special modes
 * debug_mode - create .debug files in releasedirs.
 * debug_altlog - put all .debug files in the mirror stored in the storage
 * variable. Not reccommended with first use, as not all debug info will make
 * it into that file. But might be good on a prolonged debug period on a
 * "live" site.
 * benchmark_mode - output to the user uploading how long it took to run the
 * zipscript.
 * ignore_zero_size - will allow (seemingly) zero sized file uploads.
 * ignore_zero_size_on_rescan - will ignore (seemingly) zero sized files on
 * rescan (to be used with *allowed/approved* type files).
 */
#ifndef debug_mode
#define debug_mode		FALSE
#endif
#ifndef debug_altlog
#define debug_altlog		FALSE
#endif
#ifndef debug_announce
#define debug_announce		FALSE
#endif
#ifndef benchmark_mode
#define benchmark_mode		TRUE
#endif
#ifndef ignore_zero_size
#define ignore_zero_size	FALSE
#endif
#ifndef ignore_zero_sized_on_rescan
#define ignore_zero_sized_on_rescan	FALSE
#endif

/*
 * Set this to TRUE if you wish to remove the .debug when removing a dir
 * completely. This should let users be able to delete a dir w/o access to
 * the 'wipe' command.
 */
#ifndef remove_dot_debug_on_delete
#define remove_dot_debug_on_delete	TRUE
#endif

/*
 * Set this to TRUE if you'd like to remove all hidden files (files starting
 * with a dot (''.'')) when you remove all files of the release.
 */
#ifndef remove_dot_files_on_delete
#define remove_dot_files_on_delete	FALSE
#endif
/*
 * ZIP Settings ============
 */

/*
 * Enter the (chroot'ed) path/name of unzip. This is used to test integrity
 * of zipfiles.
 * NOTE: You need the unzip bin in order to test zip-files
 */
#ifndef unzip_bin
#define unzip_bin		"/bin/unzip"
#endif


/*
 * SFV Settings ============
 */

/*
 * Calculate CRC for a filename without CRC in its SFV
 */
#ifndef sfv_calc_single_fname
#define	sfv_calc_single_fname	FALSE
#endif

/*
 * Removes duplicate entries and comments from the sfv - some lame zipscripts
 * seem to add duplicate entries :p
 */
#ifndef sfv_dupecheck
#define sfv_dupecheck		TRUE
#endif

/*
 * Writes a plain sfv - removing all comments etc
 */
#ifndef sfv_cleanup
#define sfv_cleanup		TRUE
#endif

/*
 * Also changes the case of the text in the sfv to all lowercase - this in
 * in effect turn winblows mode on. ;)
 */
#ifndef sfv_cleanup_lowercase
#define sfv_cleanup_lowercase	TRUE
#endif

/*
 * Use windows style linefeeds (<cr><lf>) in the cleaned sfv file
 */
#ifndef sfv_cleanup_crlf
#define sfv_cleanup_crlf	TRUE
#endif

/*
 * Rewrite bad sfv files
 */
#ifndef smart_sfv_write
#define smart_sfv_write		FALSE
#endif

/*
 * Should new sfv files be denied in dir? If not, the new sfv will be checked
 * and denied/allowed depending on the content of the sfv.
 */
#ifndef deny_double_sfv
#define deny_double_sfv		FALSE
#endif
#ifndef deny_double_nfo
#define deny_double_nfo		FALSE
#endif

/*
 * Exclude non sfv directories (ie group/request directory)
 */
#ifndef exclude_non_sfv_dirs
#define exclude_non_sfv_dirs	TRUE
#endif

/*
 * Force sfv to be uploaded first, before accepting any files
 */
#ifndef force_sfv_first
#define force_sfv_first		FALSE
#endif


/*
 * MP3 Settings ============
 */

/*
 * These directories will contain symlinks to your audio releases, based on
 * genre, year, artist and releasegroup. Ignore these paths if you have no
 * plans on sorting your releases. All paths are chroot'ed.
 */
#ifndef audio_genre_path
#define audio_genre_path	"/site/incoming/music.by.genre/"
#endif
#ifndef audio_artist_path
#define audio_artist_path	"/site/incoming/music.by.artist/"
#endif
#ifndef audio_year_path
#define audio_year_path		"/site/incoming/music.by.year/"
#endif
#ifndef audio_group_path
#define audio_group_path	"/site/incoming/music.by.group/"
#endif

/*
 * It is a good idea to prevent crap from filling your hds. Ignore these
 * settings if you do not plan to restrict your uploads.
 */
#ifndef allowed_constant_bitrates
#define allowed_constant_bitrates	"160,192"
#endif
#ifndef allowed_years
#define allowed_years		"2000,2001,2002,2003,2004,2005"
#endif
#ifndef banned_genres
#define banned_genres		"Christian Rap,Christian Gangsta Rap,Contemporary Christian,Christian Rock"
#endif
#ifndef allowed_genres
#define allowed_genres		"Top 40,Pop Funk,Rock,Pop"
#endif

/*
 * Audio related symlinks - set to TRUE if you wish to sort/symlink releases,
 * or FALSE if not.
 */
#ifndef audio_genre_sort
#define audio_genre_sort	FALSE
#endif
#ifndef audio_year_sort
#define audio_year_sort		FALSE
#endif
#ifndef audio_artist_sort
#define audio_artist_sort	FALSE
#endif
#ifndef audio_group_sort
#define audio_group_sort	FALSE
#endif

/*
 * Audio related checks for quality/type - here you enable/disable the
 * restriction you defined earlier. If warn is true, any banned files will
 * not be deleted, but instead a warning message will be logged to your
 * glftpd.log.
 */
#ifndef audio_cbr_check
#define audio_cbr_check		TRUE
#endif
#ifndef audio_cbr_warn
#define audio_cbr_warn		TRUE
#endif
#ifndef audio_year_check
#define audio_year_check	TRUE
#endif
#ifndef audio_year_warn
#define audio_year_warn		TRUE
#endif

/*
 * either "audio_banned_genre_check" or "audio_allowed_genre_check" should be
 * set to TRUE
 */
#ifndef audio_banned_genre_check
#define audio_banned_genre_check	TRUE
#endif
#ifndef audio_allowed_genre_check
#define audio_allowed_genre_check	FALSE
#endif
#ifndef audio_genre_warn
#define audio_genre_warn		TRUE
#endif

/*
 * Restrict releases based on vbr preset
 */
#ifndef audio_allowed_vbr_preset_check
#define audio_allowed_vbr_preset_check	FALSE
#endif
#ifndef allowed_vbr_presets
#define allowed_vbr_presets		"APS,NA"
#endif
#ifndef audio_vbr_preset_warn
#define audio_vbr_preset_warn		TRUE
#endif

/* To be *very* strict, you can choose to remove the entire releasedir if a bad
 * genre/year/whatnot is uploaded.
 */
#ifndef del_banned_release
#define del_banned_release	FALSE
#endif

/*
 * Create m3u file on release complete for audio release?
 */
#ifndef create_m3u
#define create_m3u			TRUE
#endif


/*
 * Race/Announce Settings
 * ======================
 * NOTE: You may disable announces by typing DISABLED instead of cookie string
 * (do not use DISABLED with message etc files!!!)
 */

/*
 * New leader needs this number of files more than current leader to be
 * counted as "newleader" (reduces "spam" in channel)
 */
#ifndef enable_files_ahead
#define enable_files_ahead	TRUE
#endif
#ifndef newleader_files_ahead
#define newleader_files_ahead	2
#endif

/*
 * If minium is not reached - announcement will be disabled. The number
 * entered represents the minimum number of files in the release.
 */
#ifndef min_newleader_files
#define min_newleader_files	1
#endif
#ifndef min_update_files
#define min_update_files	2
#endif
#ifndef min_halfway_files
#define min_halfway_files	10
#endif

/*
 * If minium is not reached - announcement will be disabled. The number
 * entered represents the minimum number of (estimated) MB in the release.
 */
#ifndef min_newleader_size
#define min_newleader_size	10
#endif
#ifndef min_update_size
#define min_update_size		1
#endif
#ifndef min_halfway_size
#define min_halfway_size	10
#endif


/*
 * Limit number of users/groups to display in stats.
 */
#ifndef max_users_in_top
#define max_users_in_top	7
#endif
#ifndef max_groups_in_top
#define max_groups_in_top	7
#endif
#ifndef show_stats_from_pos2_only
#define show_stats_from_pos2_only	FALSE
#endif

/*
 * Enable/disable norace announces (will be used instead of normal announces,
 * if there is only one user in race)
 */
#ifndef announce_norace
#define announce_norace		TRUE
#endif

/*
 * Get list of competitors (all racers excluding current user) - stored in %R
 * cookie
 */
#ifndef get_competitor_list
#define get_competitor_list	TRUE
#endif

#ifndef get_user_stats
#define get_user_stats		TRUE
#endif

#ifndef show_user_info
#define show_user_info		TRUE
#endif
#ifndef show_group_info
#define show_group_info		TRUE
#endif


/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * !! Below follow a series of settings that use cookies.        !!
 * !! These cookies can be found in the COOKIES file.            !!
 * !! Before you change any of these, make sure you read it.     !!
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */


/*
 * Output variables used on site (.message file)
 * =============================================
 */

/*
 * Write a file on complete in the releasedir, containing stats/raceinfo.
 */
#ifndef write_complete_message
#define write_complete_message	TRUE
#endif

/*
 * What the file should be called.
 */
#ifndef message_file_name
#define message_file_name	".message"
#endif

/*
 * Various Output
 */
#ifndef message_header
#define message_header		".--== PZS-NG v1.1 ====-----------------------------------------------.\n"
#endif
#ifndef message_user_header
#define message_user_header	"|                          U S E R T O P                             |\n+- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +\n"
#endif
#ifndef message_user_body
#define message_user_body	"| %3n %-29U %7.1mM %4fF %5.1p%% %7.0sKBs |\n"
#endif
#ifndef message_user_footer
#define message_user_footer	"+- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +\n| %3u Total %31.1mM %4fF 100.0%% %7.0aKBs |\n"
#endif
#ifndef message_group_header
#define message_group_header	"|                                                                    |\n|                          G R O U P T O P                           |\n+- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +\n"
#endif
#ifndef message_group_body
#define message_group_body	"| %3n %-29g %7.1mM %4fF %5.1p%% %7.0sKBs |\n"
#endif
#ifndef message_group_footer
#define message_group_footer	"+- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +\n| %3g Total %31.1mM %4fF 100.0%% %7.0aKBs |\n"
#endif
#ifndef message_mp3
#define message_mp3		"|                                                                    |\n|                                                                    |\n|                           I D 3 - T A G                            |\n+- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +\n| Artist : %-57x |\n| Album  : %-57W |\n| Genre  : %-34w Rate  : %3Xkbit/s      |\n| Tracks : %-34f Year  : %-14Y |\n| Encoder: %-34i Preset: %-14I |\n"
#endif
#ifndef message_footer
#define message_footer		"`-------------------------------------------------------===========--'\n"
#endif
#ifndef video_completebar
#define video_completebar	"[%Z] - ( %.0mM %fF - COMPLETE ) - [%Z]"
#endif
#ifndef audio_completebar
#define audio_completebar	"[%Z] - ( %.0mM %fF - COMPLETE - %w %Y ) - [%Z]"
#endif
#ifndef rar_completebar
#define rar_completebar		"[%Z] - ( %.0mM %fF - COMPLETE ) - [%Z]"
#endif
#ifndef other_completebar
#define other_completebar	"[%Z] - ( %.0mM %fF - COMPLETE ) - [%Z]"
#endif
#ifndef zip_completebar
#define zip_completebar		"[%Z] - ( %.0mM %fF - COMPLETE ) - [%Z]"
#endif
#ifndef del_completebar
#define del_completebar		"^\\[.*] - \\( .*F - COMPLETE.*) - \\[.*]$"
#endif
#ifndef zipscript_header
#define zipscript_header	".-== PZS-NG Zipscript-C ==-------------------------.\n"
#endif
#ifndef zipscript_sfv_ok
#define zipscript_sfv_ok	"| + SFV-file: oK!                                  |\n"
#endif
#ifndef zipscript_any_ok
#define zipscript_any_ok	"| + File: ok!                                      |\n"
#endif
#ifndef zipscript_SFV_ok
#define zipscript_SFV_ok	"| + CRC-Check: oK!                                 |\n"
#endif
#ifndef zipscript_SFV_skip
#define zipscript_SFV_skip	"| + CRC-Check: SKIPPED!                            |\n"
#endif
#ifndef zipscript_zip_ok
#define zipscript_zip_ok	"| + ZiP integrity: oK!                             |\n"
#endif
#ifndef realtime_mp3_info
#define realtime_mp3_info	"+-=[ID3tag]=------------------------===------------+\n| Title  : %-39y |\n| Artist : %-39x |\n| Album  : %-39W |\n| Genre  : %-39w |\n| Year   : %-39Y |\n"
#endif
#ifndef realtime_user_header
#define realtime_user_header	"+-=[UserTop]=-------------------===----------------+\n"
#endif
#ifndef realtime_user_body
#define realtime_user_body	"| %2n. %-15u %8.1mmB %4fF %7.0skB/s |\n"
#endif
#ifndef realtime_user_footer
#define realtime_user_footer	""
#endif
#ifndef realtime_group_header
#define realtime_group_header	"+-=[GroupTop]=--------------------===--------------+\n"
#endif
#ifndef realtime_group_body
#define realtime_group_body	"| %2n. %-15g %8.1mmB %4fF %7.0skB/s |\n"
#endif
#ifndef realtime_group_footer
#define realtime_group_footer	""
#endif
#ifndef zipscript_footer_unknown
#define zipscript_footer_unknown	"`-[ - NO - SFV - ]----------------------[%3F/???]--'\n"
#endif
#ifndef zipscript_footer_ok
#define zipscript_footer_ok	"`-[%V]----------------------[%3F/%-3f]--'\n"
#endif
#ifndef zipscript_footer_error
#define zipscript_footer_error	"| - %-46v |\n`-----------------------------------========-------'\n"
#endif
#ifndef zipscript_footer_skip
#define zipscript_footer_skip	"`--------------------------------=====-------------'\n"
#endif


/*
 * Indicators and progress-meters. ===============================
 */

/*
 * How Indicators look
 * incomplete_cd_indicator = when a multi-cd release is incomplete.
 * incomplete_indicator = when a normal release is incomplete.
 * incomplete_nfo_indicator = when a normal release is missing nfo in the dir.
 * incomplete_base_nfo_indicator = when a multi-cd release is missing nfo in
 * the base dir.
 */
#ifndef incomplete_cd_indicator
#define incomplete_cd_indicator		"../../(incomplete)-(%0)-%1"
#endif
#ifndef incomplete_indicator
#define incomplete_indicator		"../(incomplete)-%0"
#endif
#ifndef incomplete_nfo_indicator
#define incomplete_nfo_indicator	"../(no-nfo)-%0"
#endif
#ifndef incomplete_base_nfo_indicator
#define incomplete_base_nfo_indicator	"../../(no-nfo)-%1"
#endif
#ifndef progressmeter
#define progressmeter			"[%V] - %3.0p%% Complete - [%Z]"
#endif
#ifndef del_progressmeter
#define del_progressmeter		"^\\[.*] - .*%% Complete - \\[.*]$"
#endif


/*
 * Various settings ================
 */

/*
 * Enable/disable accept script (accept script is run, if file is ok)
 */
#ifndef enable_accept_script
#define enable_accept_script	FALSE
#endif
#ifndef accept_script
#define accept_script		"/bin/imdb_parse.sh"
#endif

/*
 * Enable/disable nfo script (only run on .nfo files)
 */
#ifndef enable_nfo_script
#define enable_nfo_script	FALSE
#endif
#ifndef nfo_script
#define nfo_script		"/bin/psxc-imdb.sh"
#endif

/*
 * Enable/disable complete script (complete script is run, if release is
 * complete)
 */
#ifndef enable_complete_script
#define enable_complete_script	FALSE
#endif
#ifndef complete_script
#define complete_script		"/bin/nfo_copy.sh"
#endif

/*
 * Enable/disable mp3 script (run only once, after first mp3-file is uploaded)
 */
#ifndef enable_mp3_script
#define enable_mp3_script	FALSE
#endif
#ifndef mp3_script
#define mp3_script		"/bin/ng-chown"
#endif
#ifndef mp3_script_cookies
#define mp3_script_cookies	"0 0 0 1 0 1 - \"%w\" \"%?\""
#endif

/*
 * Enable/disable unduper script (runs if sfv is uploaded after files, and
 * files are marked as bad and deleted)
 */
#ifndef enable_unduper_script
#define enable_unduper_script	TRUE
#endif
#ifndef unduper_script
#define unduper_script		"/bin/ng-undupe"
#endif

/*
 * Enable/disable banned script - executed on banned releases
 */
#ifndef enable_banned_script
#define enable_banned_script	FALSE
#endif
#ifndef banned_script
#define banned_script		"/bin/mp3-ban.sh"
#endif

/*
 * The following settings allow you to disable certain announces. This should
 * probably be done in your bot, but as of this writing, the default dzsbot
 * does not support such an option.
 */
#ifndef disable_audio_race
#define disable_audio_race		FALSE
#endif
#ifndef disable_audio_sfv
#define disable_audio_sfv		FALSE
#endif
#ifndef disable_audio_update
#define disable_audio_update		FALSE
#endif
#ifndef disable_audio_halfway
#define disable_audio_halfway		FALSE
#endif
#ifndef disable_audio_newleader
#define disable_audio_newleader		FALSE
#endif
#ifndef disable_audio_complete
#define disable_audio_complete		FALSE
#endif
#ifndef disable_audio_norace_halfway
#define disable_audio_norace_halfway	FALSE
#endif
#ifndef disable_audio_norace_complete
#define disable_audio_norace_complete	FALSE
#endif

#ifndef disable_video_race
#define disable_video_race		FALSE
#endif
#ifndef disable_video_sfv
#define disable_video_sfv		FALSE
#endif
#ifndef disable_video_update
#define disable_video_update		FALSE
#endif
#ifndef disable_video_halfway
#define disable_video_halfway		FALSE
#endif
#ifndef disable_video_newleader
#define disable_video_newleader		FALSE
#endif
#ifndef disable_video_complete
#define disable_video_complete		FALSE
#endif
#ifndef disable_video_norace_halfway
#define disable_video_norace_halfway	FALSE
#endif
#ifndef disable_video_norace_complete
#define disable_video_norace_complete	FALSE
#endif

#ifndef disable_rar_race
#define disable_rar_race		FALSE
#endif
#ifndef disable_rar_sfv
#define disable_rar_sfv			FALSE
#endif
#ifndef disable_rar_update
#define disable_rar_update		FALSE
#endif
#ifndef disable_rar_halfway
#define disable_rar_halfway		FALSE
#endif
#ifndef disable_rar_newleader
#define disable_rar_newleader		FALSE
#endif
#ifndef disable_rar_complete
#define disable_rar_complete		FALSE
#endif
#ifndef disable_rar_norace_halfway
#define disable_rar_norace_halfway	FALSE
#endif
#ifndef disable_rar_norace_complete
#define disable_rar_norace_complete	FALSE
#endif

#ifndef disable_other_race
#define disable_other_race		FALSE
#endif
#ifndef disable_other_sfv
#define disable_other_sfv		FALSE
#endif
#ifndef disable_other_update
#define disable_other_update		FALSE
#endif
#ifndef disable_other_halfway
#define disable_other_halfway		FALSE
#endif
#ifndef disable_other_newleader
#define disable_other_newleader		FALSE
#endif
#ifndef disable_other_complete
#define disable_other_complete		FALSE
#endif
#ifndef disable_other_norace_halfway
#define disable_other_norace_halfway	FALSE
#endif
#ifndef disable_other_norace_complete
#define disable_other_norace_complete	FALSE
#endif

#ifndef disable_zip_race
#define disable_zip_race		FALSE
#endif
#ifndef disable_zip_sfv
#define disable_zip_sfv			FALSE
#endif
#ifndef disable_zip_update
#define disable_zip_update		FALSE
#endif
#ifndef disable_zip_halfway
#define disable_zip_halfway		FALSE
#endif
#ifndef disable_zip_newleader
#define disable_zip_newleader		FALSE
#endif
#ifndef disable_zip_complete
#define disable_zip_complete		FALSE
#endif
#ifndef disable_zip_norace_halfway
#define disable_zip_norace_halfway	FALSE
#endif
#ifndef disable_zip_norace_complete
#define disable_zip_norace_complete	FALSE
#endif

#ifndef disable_speed_announce
#define disable_speed_announce		FALSE
#endif

#ifndef charbar_missing
#define charbar_missing			":"
#endif
#ifndef charbar_filled
#define charbar_filled			"#"
#endif

#ifndef chmod_completebar
#define	chmod_completebar		FALSE
#endif

#ifndef mark_empty_dirs_as_incomplete_on_rescan
#define mark_empty_dirs_as_incomplete_on_rescan	FALSE
#endif

#ifndef max_seconds_wait_for_lock
#define max_seconds_wait_for_lock	20
#endif
#ifndef lock_optimize
#define lock_optimize			1
#endif
#ifndef ignore_lock_timeout
#define ignore_lock_timeout		FALSE
#endif

/*
 * Some setting used in ng-chown
 * -----------------------------
 */

/* Should we allow the binary to change the uid of files/dirs?
 */
#ifndef allow_uid_change_in_ng_chown
#define allow_uid_change_in_ng_chown	FALSE
#endif
/* Should we allow the binary to change the gid of files/dirs?
 */
#ifndef allow_gid_change_in_ng_chown
#define allow_gid_change_in_ng_chown	FALSE
#endif
/* Should we allow the binary to chown the files in a dir?
 */
#ifndef allow_files_chown_in_ng_chown
#define allow_files_chown_in_ng_chown	FALSE
#endif
/* Should we allow the binary to chown the dir/file itself?
 */
#ifndef allow_dir_chown_in_ng_chown
#define allow_dir_chown_in_ng_chown	FALSE
#endif

#ifndef change_spaces_to_underscore_in_ng_chown
#define change_spaces_to_underscore_in_ng_chown	TRUE
#endif

