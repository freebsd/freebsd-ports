--- includes/session.inc.orig	2026-04-28 11:25:37 UTC
+++ includes/session.inc
@@ -428,9 +428,9 @@ if ($SysPrefs->error_logfile != '') {
 }
 
 /*
-	Uncomment the setting below when using FA on shared hosting
-	to avoid unexpeced session timeouts.
-	Make sure this directory exists and is writable!
+	Configure session settings before SessionManager::sessionStart().
+	The examples below must remain disabled here: the session is active.
+	Any custom session directory must exist and be writable.
 */
 // ini_set('session.save_path', VARLIB_PATH.'/');
 
