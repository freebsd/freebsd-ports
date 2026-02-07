--- wavegain.c.orig	2025-06-08 11:08:36 UTC
+++ wavegain.c
@@ -34,15 +34,6 @@
 #include <time.h>
 #include <ctype.h>
 
-#ifdef _WIN32
-#include <io.h>
-#include <process.h>
-#else
-# ifndef __MACOSX__
-#  include <sys/io.h>
-# endif
-#endif
-
 #include <fcntl.h>
 
 #ifndef __MACOSX__
