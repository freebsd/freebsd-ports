Work around our situation of having both libiconv in libc and libiconv from
ports installed.

--- glib/gconvert.c.orig	2014-02-08 10:15:50.000000000 +0100
+++ glib/gconvert.c	2014-02-08 10:16:52.000000000 +0100
@@ -62,7 +62,7 @@
 #error GNU libiconv in use but included iconv.h not from libiconv
 #endif
 #if !defined(USE_LIBICONV_GNU) && defined (_LIBICONV_H) \
-     && !defined (__APPLE_CC__) && !defined (__LP_64__)
+  && !defined (LIBICONV_PLUG) && !defined (__APPLE_CC__) && !defined (__LP_64__)
 #error GNU libiconv not in use but included iconv.h is from libiconv
 #endif
 
