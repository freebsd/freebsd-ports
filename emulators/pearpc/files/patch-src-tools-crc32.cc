--- src/tools/crc32.cc.orig	2007-07-15 12:46:37.000000000 +0400
+++ src/tools/crc32.cc	2007-07-15 12:46:51.000000000 +0400
@@ -97,7 +97,7 @@
 */
 
 // With this macro defined, the function runs about 35% faster, but the code is about 3 times bigger :
-#define RUN_FASTER
+//#define RUN_FASTER
 
 #define DO_CRC(b) crc = (crc >> 8) ^ crc32table[(*(byte*)&crc) ^ (b)]
 
