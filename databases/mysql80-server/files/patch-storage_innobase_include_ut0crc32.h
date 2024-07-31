--- storage/innobase/include/ut0crc32.h.orig	2024-07-12 19:15:25 UTC
+++ storage/innobase/include/ut0crc32.h
@@ -133,7 +133,9 @@ CRC32_DEFAULT
 #endif /* CRC32_ARM64 */
 
 #ifdef CRC32_ARM64_DEFAULT
+#ifndef __FreeBSD__
 #include <asm/hwcap.h>
+#endif /* __FreeBSD__ */
 #include <sys/auxv.h>
 #endif /* CRC32_ARM64_DEFAULT */
 
