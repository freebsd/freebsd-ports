--- jack/types.h.org	Tue Mar  9 20:12:17 2004
+++ jack/types.h	Tue Mar  9 20:12:22 2004
@@ -22,6 +22,14 @@
 #define __jack_types_h__
 
 #include <inttypes.h>
+#ifndef PRIu32
+#define        PRIi32          "i"     /* int32_t */
+#define        PRIu32          "u"     /* uint32_t */
+#define        PRIu64          "llu"    /* uint64_t */
+#define        SCNu64          "llu"    /* uint64_t */
+#define        PRId32          "d"     /* int32_t */
+#define        PRIx64          "llx"    /* uint64_t */
+#endif
 
 typedef char    shm_name_t[32];
 typedef int32_t jack_shmsize_t;
