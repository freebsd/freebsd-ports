--- cmake/FindClipper.cmake.orig	2020-12-24 21:19:11 UTC
+++ cmake/FindClipper.cmake
@@ -55,8 +55,8 @@ set(LIB_SEARCHDIRS 
 
 set(_deb_postfix "d")
 
-find_library(CLIPPER_LIBRARIES_RELEASE polyclipping ${LIB_SEARCHDIRS})
-find_library(CLIPPER_LIBRARIES_DEBUG polyclipping${_deb_postfix} ${LIB_SEARCHDIRS})
+find_library(CLIPPER_LIBRARIES_RELEASE libpolyclipping.so ${LIB_SEARCHDIRS})
+find_library(CLIPPER_LIBRARIES_DEBUG libpolyclipping${_deb_postfix} ${LIB_SEARCHDIRS})
 
 if(CLIPPER_LIBRARIES_${CLIPPER_BUILD_TYPE})
     set(CLIPPER_LIBRARIES "${CLIPPER_LIBRARIES_${CLIPPER_BUILD_TYPE}}")
