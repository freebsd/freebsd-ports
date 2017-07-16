--- adm/cmake/occt_csf.cmake.orig	2016-11-25 09:52:00 UTC
+++ adm/cmake/occt_csf.cmake
@@ -100,7 +100,6 @@ else()
     set (CSF_ThreadLibs  "pthread rt stdc++")
     set (CSF_OpenGlLibs  "GL")
     set (CSF_XwLibs      "X11 Xext Xmu Xi")
-    set (CSF_dl          "dl")
 
     if (USE_TCL)
       set (CSF_TclLibs     "tcl${3RDPARTY_TCL_LIBRARY_VERSION}")
@@ -127,4 +126,4 @@ else()
       set (CSF_GL2PS)
     endif()
   endif()
-endif()
\ No newline at end of file
+endif()
