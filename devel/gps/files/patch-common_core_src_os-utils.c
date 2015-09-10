--- common/core/src/os-utils.c.orig	2014-11-13 18:15:57 UTC
+++ common/core/src/os-utils.c
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #ifdef _WIN32
 #include <windows.h>
 #include <lmcons.h>
@@ -32,7 +33,7 @@
 #endif
 
 int
-__gps_subdirectories_count (name)
+__gps_subdirectories_count (char *name)
 {
   struct stat statbuf;
   int ret;
