--- cmake-proxies/cmake-modules/dependencies/wxwidgets.cmake.orig	2021-08-27 06:00:39 UTC
+++ cmake-proxies/cmake-modules/dependencies/wxwidgets.cmake
@@ -1,4 +1,10 @@
-if( ${_OPT}use_wxwidgets STREQUAL "system" ) 
+if( ${_OPT}use_wxwidgets STREQUAL "system" OR NOT ${_OPT}conan_enabled )
+    # DV: find_package will be scoped, as FindwxWidgets.cmake is rather outdated.
+    # Still - let's perform the sanity check first.
+    if( NOT wxWidgets_FOUND )
+        find_package( wxWidgets REQUIRED COMPONENTS adv base core html qa xml net )
+    endif()
+
     if( NOT TARGET wxwidgets::wxwidgets )
         add_library( wxwidgets::wxwidgets INTERFACE IMPORTED GLOBAL)
     endif()
