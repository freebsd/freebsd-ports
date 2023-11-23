Fix detection of zstd.

CMake Error at /usr/local/lib/cmake/zstd/zstdTargets.cmake:42 (message):
  Some (but not all) targets in this export set were already defined.

  Targets Defined: zstd::libzstd_shared

  Targets not yet defined: zstd::libzstd_static

Call Stack (most recent call first):
  /usr/local/lib/cmake/zstd/zstdConfig.cmake:1 (include)
  /usr/local/lib/cmake/Qt6/FindWrapZSTD.cmake:24 (find_package)
  /usr/local/lib/cmake/Qt6/QtFindPackageHelpers.cmake:156 (find_package)
  src/designer/src/lib/CMakeLists.txt:415 (qt_find_package)

Regressed by: https://code.qt.io/cgit/qt/qttools.git/commit/?h=6.6.0&id=ff5c080c2eb9267c43da6fafe953bf50076443c4

--- configure.cmake.orig	2023-09-11 09:43:37 UTC
+++ configure.cmake
@@ -7,6 +7,7 @@
 
 #### Libraries
 
+qt_find_package(WrapZSTD 1.3 PROVIDED_TARGETS WrapZSTD::WrapZSTD MODULE_NAME designer)
 
 
 #### Tests
