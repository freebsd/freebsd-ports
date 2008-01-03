--- HarmonicsPath.cc.orig	Fri Dec  7 08:13:13 2007
+++ HarmonicsPath.cc	Sun Dec 23 00:41:28 2007
@@ -31,7 +31,7 @@
 #ifdef UseLocalFiles
 static const char confFile[] = "xtide.conf";
 #else
-static const char confFile[] = "/etc/xtide.conf";
+static const char confFile[] = "%%PREFIX%%/etc/xtide.conf";
 #endif
 
 
