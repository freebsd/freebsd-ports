--- config.m4.orig	Thu Dec 25 23:33:02 2003
+++ config.m4	Wed Jul  7 14:37:18 2004
@@ -43,6 +43,9 @@
 PHP_ARG_ENABLE(gd-jis-conv, whether to enable JIS-mapped Japanese font support in GD,
 [  --enable-gd-jis-conv      GD: Enable JIS-mapped Japanese font support.], no, no)
 
+PHP_ARG_ENABLE(gd-lzw-gif, whether to enable LZW-compressed GIF support in GD,
+[  --enable-gd-lzw-gif       GD: Enable LZW-compressed GIF support.], no, no)
+
 dnl  
 dnl Checks for the configure options 
 dnl 
@@ -219,7 +222,7 @@
     ],[
       AC_MSG_ERROR([Problem with libt1.(a|so). Please check config.log for more information.]) 
     ],[
-      -L$GD_T1_DIR/lib
+      -L$GD_T1_DIR/lib -lm
     ])
   fi
 ])
@@ -236,6 +239,12 @@
   fi
 ])
 
+AC_DEFUN(PHP_GD_LZW,[
+  if test "$PHP_GD_LZW_GIF" = "yes"; then
+    USE_GD_LZW_GIF=1
+  fi
+])
+
 AC_DEFUN(PHP_GD_CHECK_VERSION,[
   PHP_CHECK_LIBRARY(gd, gdImageString16,        [AC_DEFINE(HAVE_LIBGD13,             1, [ ])], [], [ -L$GD_LIB $GD_SHARED_LIBADD ])
   PHP_CHECK_LIBRARY(gd, gdImagePaletteCopy,     [AC_DEFINE(HAVE_LIBGD15,             1, [ ])], [], [ -L$GD_LIB $GD_SHARED_LIBADD ])
@@ -256,6 +265,7 @@
   PHP_CHECK_LIBRARY(gd, gdImageColorClosestHWB, [AC_DEFINE(HAVE_COLORCLOSESTHWB,     1, [ ])], [], [ -L$GD_LIB $GD_SHARED_LIBADD ])
   PHP_CHECK_LIBRARY(gd, gdImageColorResolve,    [AC_DEFINE(HAVE_GDIMAGECOLORRESOLVE, 1, [ ])], [], [ -L$GD_LIB $GD_SHARED_LIBADD ])
   PHP_CHECK_LIBRARY(gd, gdImageGifCtx,          [AC_DEFINE(HAVE_GD_GIF_CTX,          1, [ ])], [], [ -L$GD_LIB $GD_SHARED_LIBADD ])
+  PHP_CHECK_LIBRARY(gd, gdImageGifAnimBegin,    [AC_DEFINE(HAVE_GD_GIF_ANIM,         1, [ ])], [], [ -L$GD_LIB $GD_SHARED_LIBADD ])
   PHP_CHECK_LIBRARY(gd, gdCacheCreate,          [AC_DEFINE(HAVE_GD_CACHE_CREATE,     1, [ ])], [], [ -L$GD_LIB $GD_SHARED_LIBADD ])
   PHP_CHECK_LIBRARY(gd, gdFontCacheShutdown,    [AC_DEFINE(HAVE_GD_THREAD_SAFE,      1, [ ])], [], [ -L$GD_LIB $GD_SHARED_LIBADD ])
 ])
@@ -271,6 +281,7 @@
                  libgd/gdxpm.c libgd/gdfontt.c libgd/gdfonts.c libgd/gdfontmb.c libgd/gdfontl.c \
                  libgd/gdfontg.c libgd/gdtables.c libgd/gdft.c libgd/gdcache.c libgd/gdkanji.c \
                  libgd/wbmp.c libgd/gd_wbmp.c libgd/gdhelpers.c libgd/gd_topal.c libgd/gd_gif_in.c \
+                 libgd/gd_biggif_out.c libgd/gd_lzw_out.c libgd/gd_gif_out.c \
                  libgd/xbm.c"
 
 dnl check for fabsf and floorf which are available since C99
@@ -282,6 +293,7 @@
 dnl Various checks for GD features
   PHP_GD_TTSTR
   PHP_GD_JISX0208
+  PHP_GD_LZW
   PHP_GD_JPEG
   PHP_GD_PNG
   PHP_GD_XPM
@@ -305,6 +317,9 @@
   AC_DEFINE(HAVE_GD_XBM,              1, [ ])
   AC_DEFINE(HAVE_GD_BUNDLED,          1, [ ])
   AC_DEFINE(HAVE_GD_GIF_READ,         1, [ ])
+  AC_DEFINE(HAVE_GD_GIF_CREATE,       1, [ ])
+  AC_DEFINE(HAVE_GD_GIF_CTX,          1, [ ])
+  AC_DEFINE(HAVE_GD_GIF_ANIM,         1, [ ])
   AC_DEFINE(HAVE_GD_IMAGEELLIPSE,     1, [ ])
 
 dnl Make sure the libgd/ is first in the include path
@@ -336,6 +351,11 @@
   if test -n "$USE_GD_JIS_CONV"; then
     AC_DEFINE(USE_GD_JISX0208, 1, [ ])
     GDLIB_CFLAGS="$GDLIB_CFLAGS -DJISX0208"
+  fi
+
+  if test -n "$USE_GD_LZW_GIF"; then
+    AC_DEFINE(USE_GD_LZW, 1, [ ])
+    GDLIB_CFLAGS="$GDLIB_CFLAGS -DLZW_LICENCED"
   fi
 
 else
