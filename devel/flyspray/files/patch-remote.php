--- remote.php.orig	Thu Aug 25 01:53:36 2005
+++ remote.php	Wed Oct 26 23:03:01 2005
@@ -564,6 +564,7 @@
 {
    global $fs;
    global $db;
+   global $dbprefix;
    include_once('includes/notify.inc.php');
    $notify = new Notifications;
 
