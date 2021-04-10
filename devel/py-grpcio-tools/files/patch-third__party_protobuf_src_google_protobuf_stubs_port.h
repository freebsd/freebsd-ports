--- third_party/protobuf/src/google/protobuf/stubs/port.h.orig	2021-04-10 02:52:06 UTC
+++ third_party/protobuf/src/google/protobuf/stubs/port.h
@@ -57,7 +57,7 @@
 #pragma runtime_checks("c", off)
 #endif
 #else
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <machine/endian.h>  // __BYTE_ORDER
 #else
 #include <endian.h>  // __BYTE_ORDER
