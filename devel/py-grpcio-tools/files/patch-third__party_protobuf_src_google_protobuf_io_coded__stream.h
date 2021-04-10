--- third_party/protobuf/src/google/protobuf/io/coded_stream.h.orig	2021-04-10 02:54:14 UTC
+++ third_party/protobuf/src/google/protobuf/io/coded_stream.h
@@ -131,7 +131,7 @@
 #pragma runtime_checks("c", off)
 #endif
 #else
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <machine/endian.h>  // __BYTE_ORDER
 #else
 #include <endian.h>  // __BYTE_ORDER
