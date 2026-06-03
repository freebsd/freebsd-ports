--- cmake/FindBoost.cmake.orig	2024-12-31 23:34:34 UTC
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
@@ -1000,7 +1003,7 @@ if(Boost_VERSION AND Boost_FIND_COMPONENTS)
 # On versions < 1.35, remove the System library from the considered list
 # since it wasn't added until 1.35.
 if(Boost_VERSION AND Boost_FIND_COMPONENTS)
-   if(Boost_VERSION LESS 103500)
+   if(Boost_VERSION LESS 103500 OR Boost_VERSION GREATER 107100)
      list(REMOVE_ITEM Boost_FIND_COMPONENTS system)
    endif()
 endif()
