--- adm/cmake/occt_csf.cmake.orig	2018-05-25 19:13:23 UTC
+++ adm/cmake/occt_csf.cmake
@@ -116,6 +116,5 @@ if (WIN32)
       set (CSF_OpenGlLibs  "GL")
     endif()
     set (CSF_XwLibs      "X11 Xext Xmu Xi")
-    set (CSF_dl          "dl")
   endif()
 endif()
