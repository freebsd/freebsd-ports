--- adm/cmake/occt_csf.cmake.orig	2020-11-03 14:49:43 UTC
+++ adm/cmake/occt_csf.cmake
@@ -124,7 +124,6 @@ else()
       set (CSF_OpenGlLibs  "GL")
     endif()
     set (CSF_XwLibs      "X11 Xext Xmu Xi")
-    set (CSF_dl          "dl")
     set (CSF_fontconfig  "fontconfig")
   endif()
 endif()
