--- junklib.c.orig	2014-07-31 19:03:51 UTC
+++ junklib.c
@@ -32,7 +32,6 @@
 #include <stdlib.h>
 #include <string.h>
 #if HAVE_ICONV
-  #define LIBICONV_PLUG
   #include <iconv.h>
 #elif HAVE_ICU
   #warning icu
