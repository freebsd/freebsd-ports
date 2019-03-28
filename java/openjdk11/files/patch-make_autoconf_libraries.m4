--- make/autoconf/libraries.m4
+++ make/autoconf/libraries.m4
@@ -181,9 +181,13 @@ AC_DEFUN_ONCE([LIB_SETUP_MISC_LIBS],
   LIBS="$save_LIBS"
 
   if test "x$OPENJDK_TARGET_OS" = "xbsd"; then
-    if test "x$OPENJDK_TARGET_OS_ENV" = "xbsd.openbsd"; then
-      ICONV_CFLAGS="-I$PACKAGE_PATH/include"
-      ICONV_LDFLAGS="-L$PACKAGE_PATH/lib"
+    if test "x$OPENJDK_TARGET_OS_ENV" = "xbsd.freebsd"; then
+      ICONV_CFLAGS=%%ICONV_CFLAGS%%
+      ICONV_LDFLAGS=%%ICONV_LDFLAGS%%
+      ICONV_LIBS=%%ICONV_LIBS%%
+    elif test "x$OPENJDK_TARGET_OS_ENV" = "xbsd.openbsd"; then
+      ICONV_CFLAGS="-I/usr/local/include"
+      ICONV_LDFLAGS="-L/usr/local/lib"
       ICONV_LIBS=-liconv
     else
       ICONV_CFLAGS=
