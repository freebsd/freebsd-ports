--- util/include/basic_types.h.orig
+++ util/include/basic_types.h
@@ -35,6 +35,8 @@
 typedef signed short   int16_t;
 typedef unsigned char  uint8_t;
 typedef signed char    int8_t;
+#elif __FreeBSD__
+#include <inttypes.h>
 #else
 #include <stdint.h>
 #endif
