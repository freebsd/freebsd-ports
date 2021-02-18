--- hashtab.c.orig	2019-10-02 10:26:03.003230419 -0400
+++ hashtab.c	2020-04-05 14:12:16.089254000 -0400
@@ -37,8 +37,8 @@ Boston, MA 02110-1301, USA.  */
 #include <stdio.h>
 #include "hashtab.h"
 
-#include <endian.h>
-#if __BYTE_ORDER == __BIG_ENDIAN
+#include <sys/endian.h>
+#if _BYTE_ORDER == _BIG_ENDIAN
 # define WORDS_BIGENDIAN 1
 #endif
 
