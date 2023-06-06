--- src_c/rwobject.c.orig	2023-06-06 07:10:40 UTC
+++ src_c/rwobject.c
@@ -33,11 +33,10 @@
 
 #if defined(_WIN32)
 #define PG_LSEEK _lseeki64
-#elif defined(__APPLE__)
-/* Mac does not implement lseek64 */
-#define PG_LSEEK lseek
-#else
+#elif defined(__GLIBC__)
 #define PG_LSEEK lseek64
+#else
+#define PG_LSEEK lseek
 #endif
 
 typedef struct {
