
$FreeBSD$

--- lib/copysym.c.orig	Sun Nov  4 17:03:34 2001
+++ lib/copysym.c	Sun Nov  4 17:04:08 2001
@@ -60,7 +60,7 @@
 #endif
     }
 
-  if (*outcharset)
+  if (outcharset && *outcharset)
     {
       iconv_t conv = iconv_open (outcharset, "UTF-8");
 
