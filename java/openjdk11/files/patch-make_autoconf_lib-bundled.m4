--- make/autoconf/lib-bundled.m4
+++ make/autoconf/lib-bundled.m4
@@ -58,18 +58,26 @@ AC_DEFUN_ONCE([LIB_SETUP_LIBJPEG],
 
   if test "x${with_libjpeg}" = "xbundled"; then
     USE_EXTERNAL_LIBJPEG=false
+    JPEG_CFLAGS=""
+    JPEG_LIBS=""
   elif test "x${with_libjpeg}" = "xsystem"; then
-    AC_CHECK_HEADER(jpeglib.h, [],
-        [ AC_MSG_ERROR([--with-libjpeg=system specified, but jpeglib.h not found!])])
-    AC_CHECK_LIB(jpeg, jpeg_CreateDecompress, [],
-        [ AC_MSG_ERROR([--with-libjpeg=system specified, but no libjpeg found])])
-
+    PKG_CHECK_MODULES(JPEG, libjpeg, [LIBJPEG_FOUND=yes], [LIBJPEG_FOUND=no])
+    if test "x${LIBJPEG_FOUND}" = "xno"; then
+      AC_CHECK_HEADER(jpeglib.h, [],
+          [ AC_MSG_ERROR([--with-libjpeg=system specified, but jpeglib.h not found!])])
+      AC_CHECK_LIB(jpeg, jpeg_CreateDecompress, [],
+          [ AC_MSG_ERROR([--with-libjpeg=system specified, but no libjpeg found])])
+      JPEG_CFLAGS=""
+      JPEG_LIBS="-ljpeg"
+    fi
     USE_EXTERNAL_LIBJPEG=true
   else
     AC_MSG_ERROR([Invalid use of --with-libjpeg: ${with_libjpeg}, use 'system' or 'bundled'])
   fi
 
   AC_SUBST(USE_EXTERNAL_LIBJPEG)
+  AC_SUBST(JPEG_CFLAGS)
+  AC_SUBST(JPEG_LIBS)
 ])
 
 ################################################################################
@@ -79,6 +87,10 @@ AC_DEFUN_ONCE([LIB_SETUP_GIFLIB],
 [
   AC_ARG_WITH(giflib, [AS_HELP_STRING([--with-giflib],
       [use giflib from build system or OpenJDK source (system, bundled) @<:@bundled@:>@])])
+  AC_ARG_WITH(giflib-include, [AS_HELP_STRING([--with-giflib-include],
+      [specify directory for the system giflib include files])])
+  AC_ARG_WITH(giflib-lib, [AS_HELP_STRING([--with-giflib-lib],
+      [specify directory for the system giflib library])])
 
   AC_MSG_CHECKING([for which giflib to use])
   # default is bundled
@@ -91,11 +103,40 @@ AC_DEFUN_ONCE([LIB_SETUP_GIFLIB],
 
   if test "x${with_giflib}" = "xbundled"; then
     USE_EXTERNAL_LIBGIF=false
+    GIFLIB_CFLAGS=""
+    GIFLIB_LIBS=""
   elif test "x${with_giflib}" = "xsystem"; then
-    AC_CHECK_HEADER(gif_lib.h, [],
-        [ AC_MSG_ERROR([--with-giflib=system specified, but gif_lib.h not found!])])
-    AC_CHECK_LIB(gif, DGifGetCode, [],
-        [ AC_MSG_ERROR([--with-giflib=system specified, but no giflib found!])])
+    GIFLIB_H_FOUND=no
+    if test "x${with_giflib_include}" != x; then
+      GIFLIB_CFLAGS="-I${with_giflib_include}"
+      GIFLIB_H_FOUND=yes
+    fi
+    if test "x$GIFLIB_H_FOUND" = xno; then
+      AC_CHECK_HEADER(gif_lib.h,
+          [
+            GIFLIB_CFLAGS=""
+            GIFLIB_H_FOUND=yes
+          ])
+    fi
+    if test "x$GIFLIB_H_FOUND" = xno; then
+      AC_MSG_ERROR([--with-giflib=system specified, but gif_lib.h not found!])
+    fi
+
+    GIFLIB_LIB_FOUND=no
+    if test "x${with_giflib_lib}" != x; then
+      GIFLIB_LIBS="-L${with_giflib_lib} -lgif"
+      GIFLIB_LIB_FOUND=yes
+    fi
+    if test "x$GIFLIB_LIB_FOUND" = xno; then
+      AC_CHECK_LIB(gif, DGifGetCode,
+          [
+            GIFLIB_LIBS="-lgif"
+            GIFLIB_LIB_FOUND=yes
+          ])
+    fi
+    if test "x$GIFLIB_LIB_FOUND" = xno; then
+      AC_MSG_ERROR([--with-giflib=system specified, but no giflib found!])
+    fi
 
     USE_EXTERNAL_LIBGIF=true
   else
@@ -103,6 +144,8 @@ AC_DEFUN_ONCE([LIB_SETUP_GIFLIB],
   fi
 
   AC_SUBST(USE_EXTERNAL_LIBGIF)
+  AC_SUBST(GIFLIB_CFLAGS)
+  AC_SUBST(GIFLIB_LIBS)
 ])
 
 ################################################################################
