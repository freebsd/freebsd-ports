--- scripts/mysql_config.sh.orig	2010-12-23 15:57:56.000000000 +0100
+++ scripts/mysql_config.sh	2010-12-23 15:58:49.000000000 +0100
@@ -92,7 +92,11 @@
 fix_path plugindir $plugindir_rel lib/mysql/plugin lib/plugin
 
 pkgincludedir='@pkgincludedir@'
-fix_path pkgincludedir include/mysql include
+if [ -f "$basedir/include/mysql/mysql.h" ]; then
+  pkgincludedir="$basedir/include/mysql"
+elif [ -f "$basedir/include/mysql.h" ]; then
+  pkgincludedir="$basedir/include"
+fi
 
 version='@VERSION@'
 socket='@MYSQL_UNIX_ADDR@'
