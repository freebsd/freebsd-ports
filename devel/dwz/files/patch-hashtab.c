--- hashtab.c.orig	2021-03-08 07:56:18 UTC
+++ hashtab.c
@@ -37,8 +37,8 @@ Boston, MA 02110-1301, USA.  */
 #include <stdio.h>
 #include "hashtab.h"
 
-#include <endian.h>
-#if __BYTE_ORDER == __BIG_ENDIAN
+#include <sys/endian.h>
+#if _BYTE_ORDER == _BIG_ENDIAN
 # define WORDS_BIGENDIAN 1
 #endif
 
