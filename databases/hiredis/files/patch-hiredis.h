--- hiredis.h.orig	2024-03-24 16:33:25 UTC
+++ hiredis.h
@@ -48,7 +48,7 @@ typedef long long ssize_t;
 #define HIREDIS_MAJOR 1
 #define HIREDIS_MINOR 2
 #define HIREDIS_PATCH 0
-#define HIREDIS_SONAME 1.2.1-dev
+#define HIREDIS_SONAME 1.2.1
 
 /* Connection type can be blocking or non-blocking and is set in the
  * least significant bit of the flags field in redisContext. */
