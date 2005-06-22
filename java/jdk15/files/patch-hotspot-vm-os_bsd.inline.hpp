$FreeBSD$

--- ../../hotspot/src/os/bsd/vm/os_bsd.inline.hpp	20 Dec 2004 10:06:24 -0000	1.2
+++ ../../hotspot/src/os/bsd/vm/os_bsd.inline.hpp	14 May 2005 14:58:18 -0000	1.3
@@ -29,10 +29,9 @@
 
 inline bool os::allocate_stack_guard_pages() {
   assert(uses_stack_guard_pages(), "sanity check");
-// XXXBSD: ??
-//  return thr_main();
-//  return pthread_main_np();
-  return true;
+  // Since FreeBSD 4 uses malloc() for allocating the thread stack             
+  // there is no need to do anything extra to allocate the guard pages
+  return false;
 }
 
 
