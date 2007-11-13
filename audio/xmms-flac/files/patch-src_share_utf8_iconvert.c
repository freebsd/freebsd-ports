
$FreeBSD$

--- src/share/utf8/iconvert.c.orig
+++ src/share/utf8/iconvert.c
@@ -27,6 +27,7 @@
 #include <iconv.h>
 #include <stdlib.h>
 #include <string.h>
+#include "share/alloc.h"
 
 /*
  * Convert data from one encoding to another. Return:
@@ -79,7 +80,7 @@
      * This is deliberately not a config option as people often
      * change their iconv library without rebuilding applications.
      */
-    tocode1 = (char *)malloc(strlen(tocode) + 11);
+    tocode1 = (char *)safe_malloc_add_2op_(strlen(tocode), /*+*/11);
     if (!tocode1)
       goto fail;
 
@@ -117,6 +118,8 @@
       break;
     if (obl < 6) {
       /* Enlarge the buffer */
+      if(utflen*2 < utflen) /* overflow check */
+        goto fail;
       utflen *= 2;
       newbuf = (char *)realloc(utfbuf, utflen);
       if (!newbuf)
@@ -143,7 +146,7 @@
       iconv_close(cd1);
       return ret;
     }
-    newbuf = (char *)realloc(utfbuf, (ob - utfbuf) + 1);
+    newbuf = (char *)safe_realloc_add_2op_(utfbuf, (ob - utfbuf), /*+*/1);
     if (!newbuf)
       goto fail;
     ob = (ob - utfbuf) + newbuf;
@@ -194,7 +197,7 @@
   outlen += ob - tbuf;
 
   /* Convert from UTF-8 for real */
-  outbuf = (char *)malloc(outlen + 1);
+  outbuf = (char *)safe_malloc_add_2op_(outlen, /*+*/1);
   if (!outbuf)
     goto fail;
   ib = utfbuf;
