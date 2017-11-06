Don't name-collide the variables from pkg-config with the ones this
CMake find-module is supposed to set. Follow the hints that pkg-config
provides to find the actual libraries.
--- cmake/FindGraphviz.cmake.orig	2017-09-27 13:15:56 UTC
+++ cmake/FindGraphviz.cmake
@@ -29,10 +29,8 @@
 if ( NOT WIN32 )
   
   find_package(PkgConfig)
-  pkg_check_modules( graphviz ${REQUIRED} libgvc libcdt libcgraph libpathplan )
-  if ( graphviz_FOUND )
-    set ( graphviz_INCLUDE_DIRECTORIES ${graphviz_INCLUDE_DIRS} )
-  endif ( graphviz_FOUND )
+  # Don't name-collide with the find_library() calls below, use pc_ prefix
+  pkg_check_modules( pc_graphviz ${REQUIRED} libgvc libcdt libcgraph libpathplan )
     
 endif ( NOT WIN32 )
     
@@ -43,6 +41,7 @@ find_path( graphviz_INCLUDE_DIRECTORIES
     /usr/local/include
     /usr/include
     PATH_SUFFIXES graphviz
+    HINTS ${pc_graphviz_INCLUDE_DIRECTORIES}
     )
     
 find_library( graphviz_GVC_LIBRARY
@@ -53,6 +52,7 @@ find_library( graphviz_GVC_LIBRARY
     /usr/lib64
     /usr/local/lib
     /usr/lib
+    HINTS ${pc_graphviz_LIBRARY_DIRS}
     )
 
 find_library( graphviz_CDT_LIBRARY
@@ -63,6 +63,7 @@ find_library( graphviz_CDT_LIBRARY
     /usr/lib64
     /usr/local/lib
     /usr/lib
+    HINTS ${pc_graphviz_LIBRARY_DIRS}
     )
 
 find_library( graphviz_GRAPH_LIBRARY
@@ -73,6 +74,7 @@ find_library( graphviz_GRAPH_LIBRARY
     /usr/lib64
     /usr/local/lib
     /usr/lib
+    HINTS ${pc_graphviz_LIBRARY_DIRS}
     )
 
 find_library( graphviz_PATHPLAN_LIBRARY
@@ -83,6 +85,7 @@ find_library( graphviz_PATHPLAN_LIBRARY
     /usr/lib64
     /usr/local/lib
     /usr/lib
+    HINTS ${pc_graphviz_LIBRARY_DIRS}
     )
 
 if ( graphviz_INCLUDE_DIRECTORIES AND
