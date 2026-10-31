--- /dev/null	2026-10-12 00:00:00 UTC
+++ src/cmake/modules/FindWebP.cmake
@@ -0,0 +1,81 @@
+# SPDX-License-Identifier: BSD-3-Clause
+
+# Try pkg-config first for hints/version.
+find_package(PkgConfig QUIET)
+if (PKG_CONFIG_FOUND)
+    pkg_check_modules(PC_WebP QUIET libwebp)
+endif ()
+
+find_path(WebP_INCLUDE_DIR
+          NAMES webp/decode.h
+          HINTS ${PC_WebP_INCLUDE_DIRS})
+
+find_library(WebP_LIBRARY
+             NAMES webp libwebp
+             HINTS ${PC_WebP_LIBRARY_DIRS})
+
+find_library(WebP_DEMUX_LIBRARY
+             NAMES webpdemux libwebpdemux
+             HINTS ${PC_WebP_LIBRARY_DIRS})
+
+find_library(WebP_MUX_LIBRARY
+             NAMES webpmux libwebpmux
+             HINTS ${PC_WebP_LIBRARY_DIRS})
+
+if (NOT WebP_VERSION AND PC_WebP_VERSION)
+    set(WebP_VERSION "${PC_WebP_VERSION}")
+endif ()
+
+include(FindPackageHandleStandardArgs)
+find_package_handle_standard_args(WebP
+                                  REQUIRED_VARS WebP_INCLUDE_DIR WebP_LIBRARY
+                                                WebP_DEMUX_LIBRARY WebP_MUX_LIBRARY
+                                  VERSION_VAR WebP_VERSION)
+
+if (WebP_FOUND)
+    set(WebP_INCLUDE_DIRS ${WebP_INCLUDE_DIR})
+    set(WebP_LIBRARIES ${WebP_LIBRARY} ${WebP_DEMUX_LIBRARY} ${WebP_MUX_LIBRARY})
+
+    if (NOT TARGET WebP::webp)
+        add_library(WebP::webp UNKNOWN IMPORTED)
+        set_target_properties(WebP::webp PROPERTIES
+                              IMPORTED_LOCATION "${WebP_LIBRARY}"
+                              INTERFACE_INCLUDE_DIRECTORIES "${WebP_INCLUDE_DIR}")
+    endif ()
+
+    if (NOT TARGET WebP::webpdemux)
+        add_library(WebP::webpdemux UNKNOWN IMPORTED)
+        set_target_properties(WebP::webpdemux PROPERTIES
+                              IMPORTED_LOCATION "${WebP_DEMUX_LIBRARY}"
+                              INTERFACE_INCLUDE_DIRECTORIES "${WebP_INCLUDE_DIR}")
+        target_link_libraries(WebP::webpdemux INTERFACE WebP::webp)
+    endif ()
+
+    if (NOT TARGET WebP::webpmux)
+        add_library(WebP::webpmux UNKNOWN IMPORTED)
+        set_target_properties(WebP::webpmux PROPERTIES
+                              IMPORTED_LOCATION "${WebP_MUX_LIBRARY}"
+                              INTERFACE_INCLUDE_DIRECTORIES "${WebP_INCLUDE_DIR}")
+        target_link_libraries(WebP::webpmux INTERFACE WebP::webp)
+    endif ()
+
+    # Compatibility aliases used by some projects/configs.
+    if (NOT TARGET WebP::libwebp)
+        add_library(WebP::libwebp INTERFACE IMPORTED)
+        target_link_libraries(WebP::libwebp INTERFACE WebP::webp)
+    endif ()
+    if (NOT TARGET WebP::demux)
+        add_library(WebP::demux INTERFACE IMPORTED)
+        target_link_libraries(WebP::demux INTERFACE WebP::webpdemux)
+    endif ()
+    if (NOT TARGET WebP::mux)
+        add_library(WebP::mux INTERFACE IMPORTED)
+        target_link_libraries(WebP::mux INTERFACE WebP::webpmux)
+    endif ()
+    if (NOT TARGET WebP::libwebpmux)
+        add_library(WebP::libwebpmux INTERFACE IMPORTED)
+        target_link_libraries(WebP::libwebpmux INTERFACE WebP::webpmux)
+    endif ()
+endif ()
+
+mark_as_advanced(WebP_INCLUDE_DIR WebP_LIBRARY WebP_DEMUX_LIBRARY WebP_MUX_LIBRARY)
