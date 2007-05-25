--- ../../hotspot/src/os_cpu/bsd_i486/vm/threadLS_bsd_i486.hpp.orig	Thu May 24 15:27:43 2007
+++ ../../hotspot/src/os_cpu/bsd_i486/vm/threadLS_bsd_i486.hpp	Thu May 24 19:43:59 2007
@@ -33,7 +33,7 @@
 
   static uintptr_t pd_raw_thread_id() {
     address sp = pd_sp_address();
-    return (unsigned int)sp / _pd_min_page_size;
+    return (uintptr_t) sp / _pd_min_page_size;
   }
 
   static int pd_cache_index(uintptr_t sp_page) {
