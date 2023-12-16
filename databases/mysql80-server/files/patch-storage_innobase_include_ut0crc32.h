--- storage/innobase/include/ut0crc32.h.orig	2023-11-27 21:02:58.728994000 +0100
+++ storage/innobase/include/ut0crc32.h	2023-11-27 21:04:10.010362000 +0100
@@ -132,7 +132,9 @@ CRC32_DEFAULT
 #endif /* CRC32_ARM64 */
 
 #ifdef CRC32_ARM64_DEFAULT
+#ifndef __FreeBSD__
 #include <asm/hwcap.h>
+#endif /* __FreeBSD__ */
 #include <sys/auxv.h>
 #endif /* CRC32_ARM64_DEFAULT */
 
