--- CMakeModules/FindGStreamer.cmake.orig	2022-12-01 18:17:31 UTC
+++ CMakeModules/FindGStreamer.cmake
@@ -83,18 +83,18 @@ else ()
     find_package(PkgConfig)    
 
     macro(FIND_GSTREAMER_COMPONENT _component_prefix _pkgconfig_name _header _library)
-        pkg_check_modules(${_component_prefix} QUIET ${_pkgconfig_name})
+        pkg_check_modules(PC_${_component_prefix} QUIET ${_pkgconfig_name})
 
-#        find_path(${_component_prefix}_INCLUDE_DIRS
-#            NAMES ${_header}
-#            HINTS ${PC_${_component_prefix}_INCLUDE_DIRS} ${PC_${_component_prefix}_INCLUDEDIR}
-#            PATH_SUFFIXES gstreamer-1.0
-#        )
+        find_path(${_component_prefix}_INCLUDE_DIRS
+            NAMES ${_header}
+            HINTS ${PC_${_component_prefix}_INCLUDE_DIRS} ${PC_${_component_prefix}_INCLUDEDIR}
+            PATH_SUFFIXES gstreamer-1.0
+        )
 
-#        find_library(${_component_prefix}_LIBRARIES
-#            NAMES ${_library}
-#            HINTS ${PC_${_component_prefix}_LIBRARY_DIRS} ${PC_${_component_prefix}_LIBDIR}
-#        )
+        find_library(${_component_prefix}_LIBRARIES
+            NAMES ${_library}
+            HINTS ${PC_${_component_prefix}_LIBRARY_DIRS} ${PC_${_component_prefix}_LIBDIR}
+        )
     endmacro()
 endif ()
 
