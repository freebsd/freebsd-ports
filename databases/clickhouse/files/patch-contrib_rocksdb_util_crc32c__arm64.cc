--- contrib/rocksdb/util/crc32c_arm64.cc.orig	2026-11-10 12:50:59 UTC
+++ contrib/rocksdb/util/crc32c_arm64.cc
@@ -30,6 +30,10 @@
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #endif
+#if defined(__FreeBSD__)
+#include <sys/auxv.h>
+#include <sys/elf_common.h>
+#endif

 #ifdef HAVE_ARM64_CRYPTO
 /* unfolding to compute 8 * 3 = 24 bytes parallelly */
