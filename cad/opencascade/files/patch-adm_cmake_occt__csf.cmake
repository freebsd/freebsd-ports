--- adm/cmake/occt_csf.cmake.orig	2025-05-20 11:17:10 UTC
+++ adm/cmake/occt_csf.cmake
@@ -161,7 +161,6 @@ else()
       set (CSF_OpenGlLibs "GL EGL")
     endif()
     set (CSF_OpenGlesLibs "EGL GLESv2")
-    set (CSF_dl          "dl")
     if (USE_FREETYPE)
       set (CSF_fontconfig "fontconfig")
     endif()
