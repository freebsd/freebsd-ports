--- src/LargeFileSupport.h.orig	2018-03-23 21:15:04 UTC
+++ src/LargeFileSupport.h
@@ -8,7 +8,7 @@ typedef __int64 off_type;
 #define ftell64(a)     ftell(a)
 #define fseek64(a,b,c) fseek(a,b,c)
 typedef __int64_t off_type;
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 #define ftell64(a)     ftello(a)
 #define fseek64(a,b,c) fseeko(a,b,c)
 typedef off_t off_type;
