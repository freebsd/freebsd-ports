--- opensubdiv/hbr/mesh.h.orig	2023-09-14 19:19:06 UTC
+++ opensubdiv/hbr/mesh.h
@@ -215,7 +215,7 @@ template <class T> class HbrMesh { (public)
     void SetFVarPropagateCorners(bool p) { fvarpropagatecorners = p; }
 
     // Register routines for keeping track of memory usage
-    void RegisterMemoryRoutines(void (*increment)(unsigned long bytes), void (*decrement)(unsigned long bytes)) {
+    void RegisterMemoryRoutines(void (*increment)(size_t bytes), void (*decrement)(size_t bytes)) {
         m_faceAllocator.SetMemStatsIncrement(increment);
         m_faceAllocator.SetMemStatsDecrement(decrement);
         m_vertexAllocator.SetMemStatsIncrement(increment);
