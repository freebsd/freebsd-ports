--- swift/utils/swift_build_support/swift_build_support/products/cmark.py.orig	2024-06-06 04:26:30 UTC
+++ swift/utils/swift_build_support/swift_build_support/products/cmark.py
@@ -118,4 +118,3 @@ class CMark(cmake_product.CMakeProduct):
         This phase might copy the artifacts from the previous phases into a
         destination directory.
         """
-        self.install_with_cmake(["install"], self.host_install_destdir(host_target))
