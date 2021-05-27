--- build_files/cmake/Modules/FindEmbree.cmake.orig	2019-08-12 17:21:01 UTC
+++ build_files/cmake/Modules/FindEmbree.cmake
@@ -48,14 +48,14 @@ FIND_PATH(EMBREE_INCLUDE_DIR
 
 SET(_embree_FIND_COMPONENTS
   embree3
-  embree_avx
-  embree_avx2
-  embree_sse42
-  lexers
-  math
-  simd
-  sys
-  tasking
+#  embree_avx
+#  embree_avx2
+#  embree_sse42
+#  lexers
+#  math
+#  simd
+#  sys
+#  tasking
 )
 
 SET(_embree_LIBRARIES)
