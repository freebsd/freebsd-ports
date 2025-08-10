https://github.com/vimpunk/mio/issues/110

--- vendor/mio/include/mio/detail/mmap.ipp.orig	2025-02-12 00:14:41 UTC
+++ vendor/mio/include/mio/detail/mmap.ipp
@@ -208,7 +208,7 @@ inline mmap_context memory_map(const file_handle_type 
     char* mapping_start = static_cast<char*>(::mmap(
             0, // Don't give hint as to where to map.
             length_to_map,
-            mode == access_mode::read ? PROT_READ : PROT_WRITE,
+            mode == access_mode::read ? PROT_READ : PROT_READ | PROT_WRITE,
             mode == access_mode::copy_on_write ? MAP_PRIVATE : MAP_SHARED,
             file_handle,
             aligned_offset));
