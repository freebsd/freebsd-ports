--- wvsrtv.cc.orig	Thu Jan  4 11:35:43 2007
+++ wvsrtv.cc	Fri Mar 23 02:32:59 2007
@@ -651,7 +651,7 @@
           }
           if (dir[0] == '\0') {
             FILE *configfile;
-            if ((configfile = fopen ("/etc/xtide.conf", "r"))) {
+            if ((configfile = fopen ("%%PREFIX%%/etc/xtide.conf", "r"))) {
               if (!fgets (dir, 512, configfile)) {
                 fclose (configfile);
                 return 0;
