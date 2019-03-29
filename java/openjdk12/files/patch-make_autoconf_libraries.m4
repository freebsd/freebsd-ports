--- make/autoconf/libraries.m4.orig	2019-03-28 16:54:58.823145000 -0700
+++ make/autoconf/libraries.m4	2019-03-28 16:55:45.533206000 -0700
@@ -186,9 +186,9 @@
       ICONV_LDFLAGS="-L/usr/local/lib"
       ICONV_LIBS=-liconv
     else
-      ICONV_CFLAGS=
-      ICONV_LDFLAGS=
-      ICONV_LIBS=
+      ICONV_CFLAGS=%%ICONV_CFLAGS%%
+      ICONV_LDFLAGS=%%ICONV_LDFLAGS%%
+      ICONV_LIBS=%%ICONV_LIBS%%
     fi
   else
     ICONV_CFLAGS=
