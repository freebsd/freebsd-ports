--- ../../hotspot/src/os_cpu/bsd_amd64/vm/threadLS_bsd_amd64.hpp.orig	Thu May 24 15:27:42 2007
+++ ../../hotspot/src/os_cpu/bsd_amd64/vm/threadLS_bsd_amd64.hpp	Thu May 24 16:01:24 2007
@@ -33,7 +33,7 @@
 
   static uintptr_t pd_raw_thread_id() {
     address sp = pd_sp_address();
-    return (unsigned int)sp / _pd_min_page_size;
+    return (uintptr_t) sp / _pd_min_page_size;
   }
 
   static int pd_cache_index(uintptr_t sp_page) {
