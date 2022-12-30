--- includes/session.inc.orig	2021-12-04 13:45:21 UTC
+++ includes/session.inc
@@ -397,7 +397,7 @@ foreach ($installed_extensions as $ext)
 ini_set('session.gc_maxlifetime', 36000); // moved from below.
 
 $Session_manager = new SessionManager();
-$Session_manager->sessionStart('FA'.md5(dirname(__FILE__)), 0, '/', null, True);
+$Session_manager->sessionStart('FA'.md5(dirname(__FILE__)));
 
 $_SESSION['SysPrefs'] = new sys_prefs();
 
