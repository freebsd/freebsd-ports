
$FreeBSD$

--- audiofile.m4.orig
+++ audiofile.m4
@@ -9,7 +9,7 @@
 dnl AM_PATH_AUDIOFILE([MINIMUM-VERSION, [ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]]])
 dnl Test for Audio File Library, and define AUDIOFILE_CFLAGS and AUDIOFILE_LIBS.
 dnl
-AC_DEFUN(AM_PATH_AUDIOFILE,
+AC_DEFUN([AM_PATH_AUDIOFILE],
 [dnl 
 dnl Get compiler flags and libraries from the audiofile-config script.
 dnl
