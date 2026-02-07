--- make/autoconf/libraries.m4~	2019-08-12 19:10:36.292217000 -0700
+++ make/autoconf/libraries.m4	2019-08-12 19:18:15.523606000 -0700
@@ -188,9 +188,9 @@
       ICONV_LDFLAGS="-L/usr/local/lib"
       ICONV_LIBS=-liconv
     elif test "x$OPENJDK_TARGET_OS_ENV" = "xbsd.freebsd"; then
-      ICONV_CFLAGS=-DLIBICONV_PLUG
-      ICONV_LDFLAGS=
-      ICONV_LIBS=
+      ICONV_CFLAGS=%%ICONV_CFLAGS%%
+      ICONV_LDFLAGS=%%ICONV_LDFLAGS%%
+      ICONV_LIBS=%%ICONV_LIBS%%
     else
       ICONV_CFLAGS=
       ICONV_LDFLAGS=
