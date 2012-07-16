--- Fan/Fan.pm.orig	Sun Nov 21 17:24:27 1999
+++ Fan/Fan.pm	Wed Jan 12 13:28:20 2000
@@ -48,7 +48,7 @@
 
 ;# Where configuration files are.
 BEGIN {
-	$sysconfdir = "/usr/local/etc";
+	$sysconfdir = '%%PREFIX%%/etc';
 }
 
 ;#
