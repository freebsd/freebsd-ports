--- header.php.orig	Fri Feb 20 02:49:20 2004
+++ header.php	Fri Aug 20 12:34:04 2004
@@ -2,13 +2,13 @@
 
 // Directory with Flyspray scripts. It's the directory where this file is
 // located.
-$basedir = '/var/www/flyspray';
+$basedir = '/usr/local/share/flyspray';
 
 // Flyspray uses ADODB for database access.  You will need to install
 // it somewhere on your server for Flyspray to function.  It can be installed
 // inside the Flyspray directory if you wish. The next line needs to be the
 // correct path to your adodb.inc.php file.
-include_once ( "/usr/share/adodb/adodb.inc.php" );
+include_once ( "/usr/local/share/adodb/adodb.inc.php" );
 
 //  Modify this next line to reflect the correct path to your Flyspray
 //  functions.inc.php file.
