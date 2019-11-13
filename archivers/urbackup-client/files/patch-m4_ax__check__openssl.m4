--- m4/ax_check_openssl.m4.orig	2019-11-11 19:52:41 UTC
+++ m4/ax_check_openssl.m4
@@ -53,7 +53,7 @@ AC_DEFUN([AX_CHECK_OPENSSL], [
             # then use that information and don't search ssldirs
             AC_CHECK_TOOL([PKG_CONFIG], [pkg-config])
             if test x"$PKG_CONFIG" != x""; then
-                OPENSSL_LDFLAGS=`$PKG_CONFIG openssl --libs-only-L 2>/dev/null`
+                OPENSSL_LDFLAGS=`$PKG_CONFIG openssl --libs-only-L 2>/dev/null | sed 's|-L/usr/lib||g'`
                 if test $? = 0; then
                     OPENSSL_LIBS=`$PKG_CONFIG openssl --libs-only-l 2>/dev/null`
                     OPENSSL_INCLUDES=`$PKG_CONFIG openssl --cflags-only-I 2>/dev/null`
