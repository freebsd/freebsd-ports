--- cmake/FindBoost.cmake.orig	2019-02-23 02:50:42 UTC
+++ cmake/FindBoost.cmake
@@ -170,6 +170,9 @@
 #
 # Set Boost_NO_BOOST_CMAKE to ON to disable the search for boost-cmake.
 
+# https://gitlab.kitware.com/cmake/cmake/issues/18865
+set(Boost_NO_BOOST_CMAKE ON CACHE BOOL "Disable the search for boost-cmake")
+
 #-------------------------------------------------------------------------------
 # Before we go searching, check whether boost-cmake is available, unless the
 # user specifically asked NOT to search for boost-cmake.
