--- components/gwp_asan/client/guarded_page_allocator_posix.cc.orig	2023-10-19 19:58:18 UTC
+++ components/gwp_asan/client/guarded_page_allocator_posix.cc
@@ -35,8 +35,9 @@ void GuardedPageAllocator::MarkPageInaccessible(void* 
   // mmap() a PROT_NONE page over the address to release it to the system, if
   // we used mprotect() here the system would count pages in the quarantine
   // against the RSS.
+  // MAP_ANONYMOUS requires the fd to be -1 on !linux
   void* err = mmap(ptr, state_.page_size, PROT_NONE,
-                   MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
+                   MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
   PCHECK(err == ptr) << "mmap";
 }
 
