--- include/mtp/mtp_level3.h.org
+++ include/mtp/mtp_level3.h
@@ -23,7 +23,11 @@
 #ifndef mtp_level3_h
 #define mtp_level3_h
 
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 #include <stdint.h>
 #include <sys/types.h>
