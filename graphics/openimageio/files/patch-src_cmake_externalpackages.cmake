--- src/cmake/externalpackages.cmake.orig	2026-10-12 00:00:00 UTC
+++ src/cmake/externalpackages.cmake
@@ -104,13 +104,23 @@
 if (NOT TARGET Deflate::Deflate)
     checked_find_package (libdeflate
                           VERSION_MIN 1.18)
-    alias_library_if_not_exists (Deflate::Deflate libdeflate::libdeflate_static)
-    alias_library_if_not_exists (Deflate::Deflate libdeflate::libdeflate_shared)
+    if (BUILD_SHARED_LIBS AND NOT LINKSTATIC)
+        alias_library_if_not_exists (Deflate::Deflate libdeflate::libdeflate_shared)
+        alias_library_if_not_exists (Deflate::Deflate libdeflate::libdeflate_static)
+    else ()
+        alias_library_if_not_exists (Deflate::Deflate libdeflate::libdeflate_static)
+        alias_library_if_not_exists (Deflate::Deflate libdeflate::libdeflate_shared)
+    endif ()
 endif ()
 if (NOT TARGET ZSTD::ZSTD)
     checked_find_package (zstd VERSION_MIN 1.4)
-    alias_library_if_not_exists (ZSTD::ZSTD zstd::libzstd_static)
-    alias_library_if_not_exists (ZSTD::ZSTD zstd::libzstd_shared)
+    if (BUILD_SHARED_LIBS AND NOT LINKSTATIC)
+        alias_library_if_not_exists (ZSTD::ZSTD zstd::libzstd_shared)
+        alias_library_if_not_exists (ZSTD::ZSTD zstd::libzstd_static)
+    else ()
+        alias_library_if_not_exists (ZSTD::ZSTD zstd::libzstd_static)
+        alias_library_if_not_exists (ZSTD::ZSTD zstd::libzstd_shared)
+    endif ()
 endif ()
 
 # WebP must be found before TIFF, so that an auto-built libtiff can use it.
