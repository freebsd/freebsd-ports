--- include/rijndael.h.orig	Thu Jan  4 12:26:53 2007
+++ include/rijndael.h	Thu Jan  4 12:27:11 2007
@@ -23,11 +23,11 @@
 typedef unsigned short word16;
 typedef unsigned char byte; 
 #else
-#include <asm/types.h>
+#include <sys/types.h>
 #include <stdlib.h>
 #include <string.h>
-typedef __u32 word32;
-typedef __s32 sword32;
+typedef uint32_t word32;
+typedef int32_t sword32;
 typedef unsigned short word16;
 typedef unsigned char byte; 
 #endif
