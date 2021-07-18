--- lib/kaitai/kaitaistream.cpp.orig	2021-06-28 20:04:59 UTC
+++ lib/kaitai/kaitaistream.cpp
@@ -17,6 +17,11 @@
 #define bswap_16(x) _byteswap_ushort(x)
 #define bswap_32(x) _byteswap_ulong(x)
 #define bswap_64(x) _byteswap_uint64(x)
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
 #else // !__APPLE__ or !_MSC_VER
 #include <endian.h>
 #include <byteswap.h>
