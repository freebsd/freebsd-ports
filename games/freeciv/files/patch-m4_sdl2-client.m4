--- m4/sdl2-client.m4.orig	2019-06-15 17:19:23 UTC
+++ m4/sdl2-client.m4
@@ -82,7 +82,7 @@ AC_DEFUN([FC_SDL2_PROJECT],
   ac_save_LIBS="$LIBS"
   CPPFLAGS="$CPPFLAGS $SDL2_CFLAGS"
   CFLAGS="$CFLAGS $SDL2_CFLAGS"
-  LIBS="$LIBS $SDL2_LIBS"
+  LIBS="$LIBS $SDL2_LIBS -lm"
   AC_CHECK_LIB([$1], [$2],
                [sdl2_lib_found="yes"], [sdl2_lib_found="no"
 sdl2_h_found="no"])
