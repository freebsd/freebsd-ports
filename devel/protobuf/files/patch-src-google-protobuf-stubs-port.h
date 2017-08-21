--- src/google/protobuf/stubs/port.h.orig	2017-08-15 23:39:12 UTC
+++ src/google/protobuf/stubs/port.h
@@ -256,8 +256,11 @@ static const uint64 kuint64max = GOOGLE_
 # define GOOGLE_PROTOBUF_USE_UNALIGNED 0
 #else
 // x86 and x86-64 can perform unaligned loads/stores directly.
-# define GOOGLE_PROTOBUF_USE_UNALIGNED defined(_M_X64) || \
-     defined(__x86_64__) || defined(_M_IX86) || defined(__i386__)
+# if defined(_M_X64) || defined(__x86_64__) || defined(_M_IX86) || defined(__i386__)
+#  define GOOGLE_PROTOBUF_USE_UNALIGNED 1
+# else
+#  define GOOGLE_PROTOBUF_USE_UNALIGNED 0
+# endif
 #endif
 
 #if GOOGLE_PROTOBUF_USE_UNALIGNED
