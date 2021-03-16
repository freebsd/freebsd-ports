--- src/hotspot/os_cpu/bsd_ppc/bytes_bsd_ppc.inline.hpp.orig	2021-03-15 12:55:40 UTC
+++ src/hotspot/os_cpu/bsd_ppc/bytes_bsd_ppc.inline.hpp
@@ -27,13 +27,13 @@
 #define OS_CPU_BSD_PPC_VM_BYTES_BSD_PPC_INLINE_HPP
 
 #if defined(VM_LITTLE_ENDIAN)
-#include <byteswap.h>
+#include <sys/endian.h>
 
 // Efficient swapping of data bytes from Java byte
 // ordering to native byte ordering and vice versa.
-inline u2 Bytes::swap_u2(u2 x) { return bswap_16(x); }
-inline u4 Bytes::swap_u4(u4 x) { return bswap_32(x); }
-inline u8 Bytes::swap_u8(u8 x) { return bswap_64(x); }
+inline u2 Bytes::swap_u2(u2 x) { return bswap16(x); }
+inline u4 Bytes::swap_u4(u4 x) { return bswap32(x); }
+inline u8 Bytes::swap_u8(u8 x) { return bswap64(x); }
 #endif // VM_LITTLE_ENDIAN
 
 #endif // OS_CPU_BSD_PPC_VM_BYTES_BSD_PPC_INLINE_HPP
