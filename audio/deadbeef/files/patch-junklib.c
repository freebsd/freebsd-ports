--- junklib.c.orig	2016-01-02 20:27:39 UTC
+++ junklib.c
@@ -33,7 +33,6 @@
 #include <string.h>
 #undef HAVE_ICI
 #if HAVE_ICONV
-  #define LIBICONV_PLUG
   #include <iconv.h>
 #elif HAVE_ICU
   #warning icu
