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
 
@@ -185,7 +187,7 @@ extern bool ut_poly_mul_cpu_enabled;
 @param[in]      data    8 bytes data to be processed
 @return updated CRC32 value */
 #ifdef CRC32_x86_64
-MY_ATTRIBUTE((target("sse4.2")))
+MY_ATTRIBUTE((target("crc32")))
 #elif defined(CRC32_ARM64_DEFAULT)
 MY_ATTRIBUTE((target("+crc")))
 #endif /* CRC32_x86_64 */
