--- sope-core/NGStreams/NGStreamCoder.m.orig	2015-09-16 18:26:50 UTC
+++ sope-core/NGStreams/NGStreamCoder.m
@@ -28,6 +28,10 @@
 #  include <objc/objc-class.h>
 #endif
 
+#if (defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911)) || defined(APPLE_RUNTIME) || defined(__GNUSTEP_RUNTIME__)
+#  define sel_get_name(__XXX__) sel_getName(__XXX__)
+#endif
+
 #define FINAL static inline
 
 extern id nil_method(id, SEL, ...);
