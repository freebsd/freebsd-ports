--- HarmonicsPath.cc.orig	Mon Feb 26 07:51:38 2007
+++ HarmonicsPath.cc	Fri Mar 23 02:32:10 2007
@@ -30,7 +30,7 @@
   Dstr hfile_path (getenv ("HFILE_PATH"));
   if (hfile_path.isNull()) {
     FILE *configfile;
-    if ((configfile = fopen ("/etc/xtide.conf", "r"))) {
+    if ((configfile = fopen ("%%PREFIX%%/etc/xtide.conf", "r"))) {
       hfile_path.getline (configfile);
       fclose (configfile);
     }
