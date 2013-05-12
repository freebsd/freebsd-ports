--- src/Standard/Standard_MMgrTBBalloc.cxx.orig	2012-11-12 11:47:26.000000000 +0100
+++ src/Standard/Standard_MMgrTBBalloc.cxx	2013-03-27 10:59:09.000000000 +0100
@@ -28,6 +28,9 @@
 
 // paralleling with Intel TBB
 #ifdef HAVE_TBB
+#ifdef VERSION
+#undef VERSION
+#endif
 #include <tbb/scalable_allocator.h>
 using namespace tbb;
 #else
