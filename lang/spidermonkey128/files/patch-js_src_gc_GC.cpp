--- js/src/gc/GC.cpp.orig	2025-08-11 17:07:18 UTC
+++ js/src/gc/GC.cpp
@@ -1564,7 +1564,7 @@ void GCRuntime::removeBlackRootsTracer(JSTraceDataOp t
 
 void GCRuntime::removeBlackRootsTracer(JSTraceDataOp traceOp, void* data) {
   // Can be called from finalizers
-  MOZ_ALWAYS_TRUE(EraseCallback(blackRootTracers.ref(), traceOp));
+  MOZ_ALWAYS_TRUE(EraseCallback(blackRootTracers.ref(), traceOp, data));
 }
 
 void GCRuntime::setGrayRootsTracer(JSGrayRootsTracer traceOp, void* data) {
