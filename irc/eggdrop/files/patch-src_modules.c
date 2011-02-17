--- src/modules.c	2011-01-07 06:12:27.000000000 +0100
+++ src/modules.c	2011-01-07 06:21:42.000000000 +0100
@@ -118,7 +118,7 @@
 static int module_rename(char *name, char *newname);
 
 #ifndef STATIC
-char moddir[121] = "modules/";
+char moddir[121] = __PREFIX__ "/lib/eggdrop/";
 #endif
 
 #ifdef STATIC
