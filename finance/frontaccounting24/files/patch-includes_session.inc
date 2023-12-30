--- includes/session.inc.orig	2022-07-13 06:00:09 UTC
+++ includes/session.inc
@@ -432,9 +432,8 @@ if ($SysPrefs->error_logfile != '') {
 	to avoid unexpeced session timeouts.
 	Make sure this directory exists and is writable!
 */
-// ini_set('session.save_path', VARLIB_PATH.'/');
-
-// ini_set('session.gc_maxlifetime', 36000); // 10hrs - moved to before session_manager
+ini_set('session.save_path', VARLIB_PATH.'/');
+ini_set('session.gc_maxlifetime', 36000); // 10hrs - moved to before session_manager
 
 hook_session_start(@$_POST["company_login_name"]);
 
