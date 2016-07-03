--- src/base/PdfMemoryManagement.cpp.orig	2016-07-03 09:12:06 UTC
+++ src/base/PdfMemoryManagement.cpp
@@ -34,15 +34,9 @@
 #include "PdfMemoryManagement.h"
 #include "PdfDefinesPrivate.h"
 
-#ifdef _WIN32
 #ifndef SIZE_MAX
-#ifdef _WIN64
-#define SIZE_MAX _UI64_MAX
-#else
-#define SIZE_MAX UINT_MAX
-#endif
+#define SIZE_MAX std::numeric_limits<size_t>::max()
 #endif
-#endif // _WIN32
 
 #if defined(_MSC_VER) &&  ( _MSC_VER <= 1200 )
 // errno.h isn't available in Visual C++ 6 (definitions are in stdlib.h which is already included)
