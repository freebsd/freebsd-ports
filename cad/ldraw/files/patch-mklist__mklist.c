--- ./mklist/mklist.c.orig	2013-11-15 20:23:32.000000000 +0100
+++ ./mklist/mklist.c	2013-11-15 20:25:12.000000000 +0100
@@ -53,8 +53,8 @@
 /*****************************************************************/
 /* Filename length compatibility stuff */
 /*****************************************************************/
-#ifndef _MAX_PATH
-#define _MAX_PATH 256
+#ifndef MAX_PATH
+#define MAX_PATH 256
 #endif
 char    shortfilepath[MAX_PATH];
 char    shortfilename[MAX_PATH];
@@ -84,7 +84,7 @@
 int GetShortPathName(char *longpath, char * shortpath, int psize)
 {
     strncpy(shortpath, longpath, psize);
-    return(strlen(shortpath);
+    return(strlen(shortpath));
 }
 #endif
 
