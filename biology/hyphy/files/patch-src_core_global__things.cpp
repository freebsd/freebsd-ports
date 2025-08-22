--- src/core/global_things.cpp.orig	2025-08-22 19:21:44 UTC
+++ src/core/global_things.cpp
@@ -173,7 +173,7 @@ hyPointer MemAllocate(size_t bytes, bool zero, size_t 
   result = (hyPointer)zero ? calloc(bytes, 1) : malloc(bytes);
 
   if (result == nil) {
-    HandleApplicationError(_String("Failed to allocate '") & bytes & "' bytes'",
+    HandleApplicationError(_String("Failed to allocate '") & (unsigned long)bytes & "' bytes'",
                            true);
   }
   return result;
@@ -186,7 +186,7 @@ hyPointer MemReallocate(hyPointer old_pointer, size_t 
 
   if (result == nil) {
     HandleApplicationError(
-        _String("Failed to resize memory to '") & new_size & "' bytes'", true);
+        _String("Failed to resize memory to '") & (unsigned long)new_size & "' bytes'", true);
   }
 
   return result;
