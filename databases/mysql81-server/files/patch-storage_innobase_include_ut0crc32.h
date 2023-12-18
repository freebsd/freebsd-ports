--- storage/innobase/include/ut0crc32.h.orig	2023-06-21 07:52:10 UTC
+++ storage/innobase/include/ut0crc32.h
@@ -132,7 +132,9 @@ CRC32_DEFAULT
 #endif /* CRC32_ARM64 */
 
 #ifdef CRC32_ARM64_DEFAULT
+#ifndef __FreeBSD__
 #include <asm/hwcap.h>
+#endif /* __FreeBSD__ */
 #include <sys/auxv.h>
 #endif /* CRC32_ARM64_DEFAULT */
 
