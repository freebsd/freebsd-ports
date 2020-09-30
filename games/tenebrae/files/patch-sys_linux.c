--- sys_linux.c.orig	2020-09-30 11:25:10 UTC
+++ sys_linux.c
@@ -27,7 +27,7 @@ int nostdout = 0;
 // user preference directory
 
 #if defined (USERPREF_DIR)
-char *prefdir=  ".quake";
+char *prefdir=  ".tenebrae";
 #endif
 
 #if defined (BASEDIR)
