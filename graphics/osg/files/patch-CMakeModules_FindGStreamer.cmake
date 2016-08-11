--- CMakeModules/FindGStreamer.cmake	2015-07-17 21:31:19.000000000 +0300
+++ CMakeModules/FindGStreamer.cmake	2015-02-25 22:25:34.000000000 +0300
@@ -83,18 +83,18 @@
     find_package(PkgConfig)    
 
     macro(FIND_GSTREAMER_COMPONENT _component_prefix _pkgconfig_name _header _library)
-        pkg_check_modules(${_component_prefix} QUIET ${_pkgconfig_name})
+        pkg_check_modules(PC_${_component_prefix} QUIET ${_pkgconfig_name})
 
-#        find_path(${_component_prefix}_INCLUDE_DIRS
-#            NAMES ${_header}
-#            HINTS ${PC_${_component_prefix}_INCLUDE_DIRS} ${PC_${_component_prefix}_INCLUDEDIR}
-#            PATH_SUFFIXES gstreamer-1.0
-#        )
-
-#        find_library(${_component_prefix}_LIBRARIES
-#            NAMES ${_library}
-#            HINTS ${PC_${_component_prefix}_LIBRARY_DIRS} ${PC_${_component_prefix}_LIBDIR}
-#        )
+        find_path(${_component_prefix}_INCLUDE_DIRS
+            NAMES ${_header}
+            HINTS ${PC_${_component_prefix}_INCLUDE_DIRS} ${PC_${_component_prefix}_INCLUDEDIR}
+            PATH_SUFFIXES gstreamer-1.0
+        )
+
+        find_library(${_component_prefix}_LIBRARIES
+            NAMES ${_library}
+            HINTS ${PC_${_component_prefix}_LIBRARY_DIRS} ${PC_${_component_prefix}_LIBDIR}
+        )
     endmacro()
 endif ()
 
