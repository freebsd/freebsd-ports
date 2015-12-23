--- sha1.c.orig	2014-10-31 13:30:04 UTC
+++ sha1.c
@@ -86,6 +86,13 @@ A million repetitions of "a"
 #include <string.h>
 
 #include "os_types.h"
+
+#include <sha.h>
+#ifndef SHA1_DIGEST_SIZE
+#	define SHA1_DIGEST_SIZE	20
+#endif
+
+#if 0
 #include "sha1.h"
 
 void SHA1_Transform(uint32_t state[5], const uint8_t buffer[64]);
@@ -260,7 +267,6 @@ void SHA1_Final(SHA1_CTX* context, uint8
 
 /*************************************************************/
 
-#if 0
 int main(int argc, char** argv)
 {
 int i, j;
