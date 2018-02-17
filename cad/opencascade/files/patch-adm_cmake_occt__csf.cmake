--- adm/cmake/occt_csf.cmake.orig	2017-08-30 13:27:56 UTC
+++ adm/cmake/occt_csf.cmake
@@ -111,6 +111,5 @@ if (WIN32)
     set (CSF_ThreadLibs  "pthread rt stdc++")
     set (CSF_OpenGlLibs  "GL")
     set (CSF_XwLibs      "X11 Xext Xmu Xi")
-    set (CSF_dl          "dl")
   endif()
 endif()
