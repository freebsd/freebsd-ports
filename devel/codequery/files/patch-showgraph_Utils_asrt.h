--- showgraph/Utils/asrt.h.orig	2017-07-28 19:53:18 UTC
+++ showgraph/Utils/asrt.h
@@ -22,6 +22,10 @@
 #ifndef ASRT_H
 #define ASRT_H
 
+#ifdef assert
+#  undef assert
+#endif
+
 /**
  * Assert macro that works only in debug version
  * @ingroup Asserts
