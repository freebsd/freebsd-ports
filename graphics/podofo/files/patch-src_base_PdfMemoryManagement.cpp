--- src/base/PdfMemoryManagement.cpp.orig	2016-06-16 16:10:23 UTC
+++ src/base/PdfMemoryManagement.cpp
@@ -44,6 +44,14 @@
 #endif
 #endif // _WIN32
 
+#ifdef __FreeBSD__
+#if __WORDSIZE == 64
+#define SIZE_MAX UINT64_MAX
+#else
+#define SIZE_MAX UINT_MAX
+#endif
+#endif
+
 #if defined(_MSC_VER) &&  ( _MSC_VER <= 1200 )
 // errno.h isn't available in Visual C++ 6 (definitions are in stdlib.h which is already included)
 #else
