--- libast.m4.orig	Sun Aug  8 22:35:57 2004
+++ libast.m4	Sun Aug  8 22:36:15 2004
@@ -199,8 +199,6 @@
     LIBAST_IMLIB2_SUPPORT=""
     if test $USE_IMLIB -eq 1 ; then
         AC_CHECK_LIB(m, pow, LIBS="-lm $LIBS")
-        AC_CHECK_LIB(dl, dlopen, LIBS="-ldl $LIBS")
-        AC_CHECK_LIB(ttf, TT_Init_FreeType, GRLIBS="-lttf $GRLIBS", , $GRLIBS)
         AC_CHECK_LIB(Imlib2, imlib_create_image, [
                          GRLIBS="-lImlib2 $GRLIBS"
                          AC_DEFINE(LIBAST_IMLIB2_SUPPORT)
