--- ./cmake/modules/FindGdk.cmake.orig	2009-03-17 04:52:18.000000000 -0400
+++ ./cmake/modules/FindGdk.cmake	2009-06-08 04:44:58.000000000 -0400
@@ -16,33 +16,23 @@
   if(NOT WIN32)
     # use pkg-config to get the directories and then use these values
     # in the FIND_PATH() and FIND_LIBRARY() calls
-    INCLUDE(UsePkgConfig)
-  
-    PKGCONFIG(gdk-pixbuf-2.0 _GDKIncDir _GDKLinkDir _GDKLinkFlags _GDKCflags)
-  
-    set(GDK_DEFINITIONS ${_GDKCflags})
+    INCLUDE(FindPkgConfig)
+    PKG_CHECK_MODULES(GDK gdk-pixbuf-2.0)
+
   endif(NOT WIN32)
 
-  FIND_PATH(GDK_INCLUDE_DIR gdk-pixbuf/gdk-pixbuf.h /usr/include/gtk-2.0
-    ${_GDKIncDir}
-  )
+  FIND_PATH(GDK_INCLUDE_DIR NAMES gdk-pixbuf/gdk-pixbuf.h
+    PATHS ${GDK_INCLUDE_DIRS} PATH_SUFFIXES gtk-2.0)
   
-  FIND_LIBRARY(GDK_LIBRARIES NAMES gdk_pixbuf-2.0
-    PATHS
-    ${_GDKLinkDir}
-  )
-
-  if (GDK_INCLUDE_DIR AND GDK_LIBRARIES)
-    SET(GDK_FOUND TRUE)
-  else (GDK_INCLUDE_DIR AND GDK_LIBRARIES)
-    SET(GDK_FOUND FALSE)
-  endif (GDK_INCLUDE_DIR AND GDK_LIBRARIES)
+  FIND_LIBRARY(GDK_LIBRARY NAMES gdk_pixbuf-2.0 PATHS ${GDK_LIBRARY_DIRS})
 
   include(FindPackageHandleStandardArgs)
-  FIND_PACKAGE_HANDLE_STANDARD_ARGS(Gdk DEFAULT_MSG GDK_INCLUDE_DIR GDK_LIBRARIES )
+  FIND_PACKAGE_HANDLE_STANDARD_ARGS(Gdk DEFAULT_MSG GDK_INCLUDE_DIR GDK_LIBRARY)
+
+  IF(GDK_FOUND)
+    SET(GDK_LIBRARIES ${GDK_LIBRARY})
+  ENDIF(GDK_FOUND)
  
-  MARK_AS_ADVANCED(GDK_INCLUDE_DIR GDK_LIBRARIES)
+  MARK_AS_ADVANCED(GDK_INCLUDE_DIR GDK_LIBRARY)
   
 endif (GDK_INCLUDE_DIR AND GDK_LIBRARIES)
-
-macro_bool_to_01(GDK_FOUND GDK_FOUND)
