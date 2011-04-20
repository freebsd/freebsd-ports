--- src/errors.h.orig	2011-04-14 19:57:13.000000000 +0400
+++ src/errors.h	2011-04-14 20:00:25.000000000 +0400
@@ -20,9 +20,11 @@
     PNGNQ_LOG_ERR(__VA_ARGS__)\
     fflush(stderr);
 
-#define PNGNQ_WARNING(...) (fprintf(stderr,"pngnq - Warning: "));\
-    fprintf(stderr, __VA_ARGS__);\
-    PNGNQ_LOG_WARNING(__VA_ARGS__)\
-    fflush(stderr);
+#define PNGNQ_WARNING(...)                                \
+    do {                                                  \
+        fprintf(stderr, "pngnq - Warning: " __VA_ARGS__); \
+        PNGNQ_LOG_WARNING(__VA_ARGS__)                    \
+        fflush(stderr);                                   \
+    } while (0)
 
 #define PNGNQ_MESSAGE(...) {if(verbose) {fprintf(stderr,__VA_ARGS__);fflush(stderr);}}
