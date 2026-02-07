--- acinclude.m4.orig	2000-10-07 15:39:52.000000000 +0200
+++ acinclude.m4	2007-11-05 23:59:45.000000000 +0100
@@ -8,7 +8,7 @@
 dnl AM_PATH_SDL([MINIMUM-VERSION, [ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]]])
 dnl Test for SDL, and define SDL_CFLAGS and SDL_LIBS
 dnl
-AC_DEFUN(AM_PATH_SDL,
+AC_DEFUN([AM_PATH_SDL],
 [dnl 
 dnl Get the cflags and libraries from the sdl-config script
 dnl
