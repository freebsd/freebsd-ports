--- src/p_mach.cpp.orig	2020-01-22 21:29:58 UTC
+++ src/p_mach.cpp
@@ -467,7 +467,7 @@ PackMachBase<T>::compare_segment_command(void const *c
     if (a->vmsize)             return -1;  // 'a' is first
     if (b->vmsize)             return  1;  // 'a' is last
     // What could remain?
-                               return  0;
+    return  0;
 }
 
 #undef PAGE_MASK
