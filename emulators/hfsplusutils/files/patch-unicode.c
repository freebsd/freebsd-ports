--- libhfsp/src/unicode.c.orig	Tue Mar  5 14:50:29 2002
+++ libhfsp/src/unicode.c	Tue Nov 11 14:53:25 2003
@@ -14,9 +14,8 @@
 # endif
  
 #include <stdlib.h>
-#include <endian.h>
-#include <byteswap.h>
-#include <linux/string.h>
+#include <sys/endian.h>
+#include <string.h>
 
 #define __USE_GNU
     /* need wcsrtomb */
