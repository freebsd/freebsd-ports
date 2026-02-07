--- src/options.h.orig	2021-02-18 22:20:24 UTC
+++ src/options.h
@@ -136,7 +136,7 @@
 /*
  * OPTION: Use the POSIX "termios" methods in "main-gcu.c"
  */
-/* #define USE_TPOSIX */
+#define USE_TPOSIX
 
 /*
  * OPTION: Use the "termio" methods in "main-gcu.c"
@@ -154,7 +154,7 @@
  * OPTION: Use the "curs_set()" call in "main-gcu.c".
  * Hack -- This option will not work on most BSD machines
  */
-#if defined(SYS_V) || defined(linux)
+#if defined(SYS_V) || defined(linux) || defined(__FreeBSD__)
 # define USE_CURS_SET
 #endif
 
@@ -571,7 +571,7 @@
 /*
  * OPTION: Attempt to prevent all "cheating"
  */
-/* #define VERIFY_HONOR */
+#define VERIFY_HONOR
 
 
 /*
