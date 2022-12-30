--- includes/session.inc.orig	2021-12-04 13:45:21 UTC
+++ includes/session.inc
@@ -397,7 +397,7 @@ foreach ($installed_extensions as $ext)
 ini_set('session.gc_maxlifetime', 36000); // moved from below.
 
 $Session_manager = new SessionManager();
-$Session_manager->sessionStart('FA'.md5(dirname(__FILE__)), 0, '/', null, True);
+$Session_manager->sessionStart('FA'.md5(dirname(__FILE__)));
 
 $_SESSION['SysPrefs'] = new sys_prefs();
 
@@ -431,9 +431,8 @@ if ($SysPrefs->error_logfile != '') {
 	to avoid unexpeced session timeouts.
 	Make sure this directory exists and is writable!
 */
-// ini_set('session.save_path', VARLIB_PATH.'/');
-
-// ini_set('session.gc_maxlifetime', 36000); // 10hrs - moved to before session_manager
+ini_set('session.save_path', VARLIB_PATH.'/');
+ini_set('session.gc_maxlifetime', 36000); // 10hrs - moved to before session_manager
 
 hook_session_start(@$_POST["company_login_name"]);
 
