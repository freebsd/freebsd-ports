--- header.php.orig	Sun Oct 23 01:11:14 2005
+++ header.php	Wed Oct 26 04:16:53 2005
@@ -4,8 +4,11 @@
 // move flyspray.conf.php to a directory where a browser can't access it.
 // (RECOMMENDED).
 
-// Turn off PHP notices
-error_reporting(E_ALL & -E_NOTICE);
+// You might like to uncomment the next line if you are receiving lots of
+// PHP NOTICE errors.  We are in the process of making Flyspray stop making
+// these errors, but this will help hide them until we are finished.
+
+//error_reporting(E_ALL & ~E_NOTICE);
 
 // Check PHP Version (Must Be at least 4.3)
 // For 0.9.9, this should redirect to the error page
