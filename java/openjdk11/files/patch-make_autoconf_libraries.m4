--- make/autoconf/libraries.m4
+++ make/autoconf/libraries.m4
@@ -182,8 +182,8 @@ AC_DEFUN_ONCE([LIB_SETUP_MISC_LIBS],
 
   if test "x$OPENJDK_TARGET_OS" = "xbsd"; then
     if test "x$OPENJDK_TARGET_OS_ENV" = "xbsd.openbsd"; then
-      ICONV_CFLAGS="-I$PACKAGE_PATH/include"
-      ICONV_LDFLAGS="-L$PACKAGE_PATH/lib"
+      ICONV_CFLAGS="-I/usr/local/include"
+      ICONV_LDFLAGS="-L/usr/local/lib"
       ICONV_LIBS=-liconv
     else
       ICONV_CFLAGS=
