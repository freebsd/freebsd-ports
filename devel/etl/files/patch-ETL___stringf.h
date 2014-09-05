--- ETL/_stringf.h.orig
+++ ETL/_stringf.h
@@ -57,7 +57,7 @@
 
 _ETL_BEGIN_CDECLS
 
-#if defined(__APPLE__) || defined(__CYGWIN__) || defined(_WIN32)
+#if defined(__clang__) || defined(__APPLE__) || defined(__CYGWIN__) || defined(_WIN32)
 #define ETL_NO_THROW
 #else
 #define ETL_NO_THROW throw()
