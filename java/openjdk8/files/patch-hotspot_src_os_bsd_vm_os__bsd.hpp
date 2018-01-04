--- hotspot/src/os/bsd/vm/os_bsd.hpp.orig	2017-12-01 00:32:02 UTC
+++ hotspot/src/os/bsd/vm/os_bsd.hpp
@@ -87,7 +87,7 @@ class Bsd {
   static void rebuild_cpu_to_node_map();
   static GrowableArray<int>* cpu_to_node()    { return _cpu_to_node; }
 
-  static bool hugetlbfs_sanity_check(bool warn, size_t page_size);
+  static bool superpage_sanity_check(bool warn, size_t *page_size);
 
  public:
 
