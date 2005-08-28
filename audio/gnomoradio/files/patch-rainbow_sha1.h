--- rainbow/sha1.h.orig	Tue Aug 16 17:32:22 2005
+++ rainbow/sha1.h	Tue Aug 16 17:33:26 2005
@@ -22,7 +22,7 @@
 #ifndef _SHA1_H_
 #define _SHA1_H_
 
-#include <stdint.h>
+#include <unistd.h>
 /*
  * If you do not have the ISO standard stdint.h header file, then you
  * must typdef the following:
@@ -57,7 +57,7 @@
     uint32_t Length_High;           /* Message length in bits      */
 
                                /* Index into message block array   */
-    int_least16_t Message_Block_Index;
+    int16_t Message_Block_Index;
     uint8_t Message_Block[64];      /* 512-bit message blocks      */
 
     int Computed;               /* Is the digest computed?         */
