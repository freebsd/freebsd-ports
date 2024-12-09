--- sproton/src/i18n.cpp.orig	2024-12-09 20:40:55 UTC
+++ sproton/src/i18n.cpp
@@ -6,6 +6,10 @@
 #include "resources.h"
 #include "logging.h"
 
+#if defined(__FreeBSD__)
+#  include <sys/endian.h>
+#endif
+
 #if defined(_MSC_VER)
 #include <cstdlib>
 static inline uint32_t bswap32_(uint32_t value)
