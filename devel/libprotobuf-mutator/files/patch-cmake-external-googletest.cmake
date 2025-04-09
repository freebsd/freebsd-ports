--- cmake/external/googletest.cmake.orig	2025-02-26 00:43:54 UTC
+++ cmake/external/googletest.cmake
@@ -30,7 +30,7 @@ foreach(lib IN LISTS GTEST_BOTH_LIBRARIES)
       set(LIB_PATH ${GTEST_INSTALL_DIR}/lib/${lib}.lib)
     endif()
   else()
-    set(LIB_PATH ${GTEST_INSTALL_DIR}/lib/lib${lib}.a)
+    set(LIB_PATH ${LOCALBASE}/lib/lib${lib}.so)
   endif()
   list(APPEND GTEST_BUILD_BYPRODUCTS ${LIB_PATH})
 
