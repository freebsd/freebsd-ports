--- config.h.orig	2016-05-31 18:04:39 UTC
+++ config.h
@@ -137,7 +137,7 @@
 /*
  * OPTION: Use the POSIX "termios" methods in "main-gcu.c"
  */
-/* #define USE_TPOSIX */
+#define USE_TPOSIX
 
 /*
  * OPTION: Use the "termio" methods in "main-gcu.c"
@@ -155,7 +155,7 @@
  * OPTION: Use the "curs_set()" call in "main-gcu.c".
  * Hack -- This option will not work on most BSD machines
  */
-#if defined(SYS_V) || defined(linux)
+#if defined(SYS_V) || defined(linux) || defined(__FreeBSD__)
 # define USE_CURS_SET
 #endif
 
@@ -570,7 +570,7 @@
 /*
  * OPTION: Attempt to prevent all "cheating"
  */
-/* #define VERIFY_HONOR */
+#define VERIFY_HONOR
 
 
 /*
