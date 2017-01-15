--- hotspot/src/share/vm/runtime/virtualspace.cpp.orig
+++ hotspot/src/share/vm/runtime/virtualspace.cpp
@@ -342,7 +342,7 @@ ReservedHeapSpace::ReservedHeapSpace(siz
                 (UseCompressedOops && (Universe::narrow_oop_base() != NULL) &&
                  Universe::narrow_oop_use_implicit_null_checks()) ?
                   lcm(os::vm_page_size(), alignment) : 0) {
-  if (base() > 0) {
+  if (base() != NULL) {
     MemTracker::record_virtual_memory_type((address)base(), mtJavaHeap);
   }
 
