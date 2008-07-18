--- base64.c.orig	2005-01-17 14:19:18.000000000 -0900
+++ base64.c	2008-07-14 21:41:47.000000000 -0800
@@ -1,6 +1,9 @@
 /*
     Public Base64 conversion tables
 */
+
+#include <string.h>
+
 unsigned char B64ABC[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
 unsigned char b64buf[256];
 
