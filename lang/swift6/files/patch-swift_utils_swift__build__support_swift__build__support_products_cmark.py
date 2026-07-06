--- swift/utils/swift_build_support/swift_build_support/products/cmark.py.orig	2025-12-09 23:45:54 UTC
+++ swift/utils/swift_build_support/swift_build_support/products/cmark.py
@@ -114,4 +114,3 @@ class CMark(cmake_product.CMakeProduct):
         This phase might copy the artifacts from the previous phases into a
         destination directory.
         """
-        self.install_with_cmake(["install"], self.host_install_destdir(host_target))
