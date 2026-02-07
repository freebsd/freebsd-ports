--- cmake/FindGST.cmake.orig	2025-10-17 17:11:22 UTC
+++ cmake/FindGST.cmake
@@ -2,14 +2,14 @@ find_path(GST_INCLUDE_DIR
   NAMES gst/gst.h
   HINTS
     "${GST_INCLUDE_DIRS}"
-  PATHS /usr/include/gstreamer-1.0
+  PATHS %%LOCALBASE%%/include/gstreamer-1.0
 )
 
 find_path(GL_INCLUDE_DIR
   NAMES glib.h
   HINTS
     "${GL_INCLUDE_DIRS}"
-  PATHS /usr/include/glib-2.0
+  PATHS %%LOCALBASE%%/include/glib-2.0
 )
 
 find_path(GLIB_INCLUDE_DIR
@@ -19,21 +19,21 @@ find_path(GLIB_INCLUDE_DIR
   PATHS /usr/lib/x86_64-linux-gnu/glib-2.0
         /usr/lib/x86_64-linux-gnu/glib-2.0/include
         /usr/lib64/glib-2.0
-        /usr/lib/glib-2.0
+        %%LOCALBASE%%/lib/glib-2.0/include
 )
 
 find_library(GST_LIBRARY
   NAMES gstreamer-1.0
   HINTS
     "${GST_LIBRARY_DIRS}"
-  PATHS /usr/lib/x86_64-linux-gnu
+  PATHS %%LOCALBASE%%/lib
 )
 
 find_library(GL_LIBRARY
   NAMES glib-2.0
   HINTS
     "${GL_LIBRARY_DIRS}"
-  PATHS /usr/lib/x86_64-linux-gnu
+  PATHS %%LOCALBASE%%/lib
 )
 
 include(FindPackageHandleStandardArgs)
