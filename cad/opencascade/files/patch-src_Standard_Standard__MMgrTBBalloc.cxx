--- src/Standard/Standard_MMgrTBBalloc.cxx.orig	2017-08-30 13:28:31 UTC
+++ src/Standard/Standard_MMgrTBBalloc.cxx
@@ -18,6 +18,9 @@
 
 // paralleling with Intel TBB
 #ifdef HAVE_TBB
+#ifdef VERSION
+#undef VERSION
+#endif
 #include <tbb/scalable_allocator.h>
 using namespace tbb;
 #else
