--- lib/kaitai/kaitai/kaitaistream.cpp	2024-12-23 17:32:09.000000000 -0800
+++ lib/kaitai/kaitai/kaitaistream.cpp	2024-12-26 10:01:17.216933000 -0800
@@ -10,6 +10,11 @@
 #define __BYTE_ORDER    BYTE_ORDER
 #define __BIG_ENDIAN    BIG_ENDIAN
 #define __LITTLE_ENDIAN LITTLE_ENDIAN
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
 #elif defined(_MSC_VER) // !__APPLE__
 #include <stdlib.h>
 #define __LITTLE_ENDIAN     1234
@@ -874,4 +879,4 @@
 
 #else
 #error Need to decide how to handle strings: please define one of: KS_STR_ENCODING_ICONV, KS_STR_ENCODING_WIN32API, KS_STR_ENCODING_NONE
-#endif
\ No newline at end of file
+#endif
