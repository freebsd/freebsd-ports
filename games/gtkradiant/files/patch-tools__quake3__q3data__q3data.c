--- tools/quake3/q3data/q3data.c.orig	2006-02-10 22:01:20 UTC
+++ tools/quake3/q3data/q3data.c
@@ -37,8 +37,6 @@
 
 // bogus externs for some TA hacks (common/ using them against q3map)
 char *moddir = NULL;
-// some old defined that was in cmdlib lost during merge
-char writedir[1024];
 
 #if defined (__linux__) || defined (__APPLE__)
 #define strlwr strlower
@@ -341,7 +339,7 @@
 #else
 
 #include <sys/types.h>
-#ifndef WIN32
+#ifdef NeXT
 #include <sys/dir.h>
 #else
 #include <sys/dirent.h>
