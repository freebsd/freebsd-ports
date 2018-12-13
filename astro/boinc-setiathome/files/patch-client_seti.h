--- client/seti.h.orig	2018-12-13 10:21:28 UTC
+++ client/seti.h
@@ -53,9 +53,9 @@ typedef uint64_t sh_uint8_t;
 
 #ifdef PRId64
 // If print formats are defined
-#define SINT8_FMT "%"PRId64
+#define SINT8_FMT "%" PRId64
 #define SINT8_FMT_CAST(x) (x)
-#define UINT8_FMT "%"PRIu64
+#define UINT8_FMT "%" PRIu64
 #define UINT8_FMT_CAST(x) (x)
 #else 
 // play it safe.  It'll work through 49 bits at least.
