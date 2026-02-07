--- pdfium/third_party/base/logging.h.orig	2017-04-16 14:53:52 UTC
+++ pdfium/third_party/base/logging.h
@@ -10,7 +10,7 @@
 
 #ifndef _WIN32
 #define NULL_DEREF_IF_POSSIBLE \
-  *(reinterpret_cast<volatile char*>(NULL) + 42) = 0x42;
+  *(reinterpret_cast<volatile char*>(__null) + 42) = 0x42;
 #else
 #define NULL_DEREF_IF_POSSIBLE
 #endif
