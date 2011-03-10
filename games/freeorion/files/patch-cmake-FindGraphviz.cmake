--- cmake/FindGraphviz.cmake.orig	2010-09-14 10:12:19.000000000 +0200
+++ cmake/FindGraphviz.cmake	2010-09-14 10:12:52.000000000 +0200
@@ -10,7 +10,7 @@
 
 find_package(PkgConfig)
 if (PKG_CONFIG_FOUND)
-    pkg_check_modules(GRAPHVIZ libagraph libcdt libcgraph libgraph libgvc libpathplan)
+    pkg_check_modules(GRAPHVIZ libcdt libcgraph libgraph libgvc libpathplan)
     if (GRAPHVIZ_FOUND)
         set(GRAPHVIZ_INCLUDE_DIR ${GRAPHVIZ_INCLUDE_DIRS})
     endif ()
@@ -26,11 +26,6 @@
 )
 
 find_library(
-    GRAPHVIZ_AGRAPH_LIBRARY
-    NAMES agraph 
-    PATHS ${GRAPHVIZ_LIBRARY_DIRS}
-)
-find_library(
     GRAPHVIZ_CDT_LIBRARY
     NAMES cdt 
     PATHS ${GRAPHVIZ_LIBRARY_DIRS}
@@ -57,7 +52,6 @@
 )
 
 if (GRAPHVIZ_INCLUDE_DIR AND
-    GRAPHVIZ_AGRAPH_LIBRARY AND
     GRAPHVIZ_CDT_LIBRARY AND
     GRAPHVIZ_CGRAPH_LIBRARY AND
     GRAPHVIZ_GRAPH_LIBRARY AND
@@ -65,7 +59,6 @@
     GRAPHVIZ_PATHPLAN_LIBRARY)
     set(GRAPHVIZ_FOUND true)
     set(GRAPHVIZ_LIBRARIES
-        ${GRAPHVIZ_AGRAPH_LIBRARY}
         ${GRAPHVIZ_CDT_LIBRARY}
         ${GRAPHVIZ_CGRAPH_LIBRARY}
         ${GRAPHVIZ_GRAPH_LIBRARY}
