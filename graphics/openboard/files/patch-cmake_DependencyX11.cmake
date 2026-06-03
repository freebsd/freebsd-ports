--- cmake/DependencyX11.cmake.orig	2026-03-23 11:30:46 UTC
+++ cmake/DependencyX11.cmake
@@ -1,18 +1,8 @@
-# Find FFmpeg
+# Find X11
+find_library(X11_LIB X11 PATHS %%LOCALBASE%%)
 
-find_package(X11 QUIET)
-
-if (X11_FOUND)
-    target_link_libraries(${PROJECT_NAME}
-        X11
-    )
+if(X11_LIB)
+    target_link_libraries(${PROJECT_NAME} ${X11_LIB})
 else()
-    find_package(PkgConfig REQUIRED)
-    pkg_check_modules(X11 REQUIRED x11)
-
-    if (X11_FOUND)
-        target_link_libraries(${PROJECT_NAME} 
-            PkgConfig::X11
-        )
-    endif()
+    message(FATAL_ERROR "X11 library not found")
 endif()
