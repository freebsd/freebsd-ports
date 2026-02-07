--- audio.c.orig	2025-06-08 11:07:50 UTC
+++ audio.c
@@ -32,14 +32,6 @@
 #include <sys/stat.h>
 #include <math.h>
 
-#ifdef _WIN32
-#include <io.h>
-#else
-# ifndef __MACOSX__
-#  include <sys/io.h>
-# endif
-#endif
-
 #include <fcntl.h>
 
 #ifndef __MACOSX__
