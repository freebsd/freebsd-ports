--- adm/cmake/occt_csf.cmake.orig	2021-10-30 11:13:37 UTC
+++ adm/cmake/occt_csf.cmake
@@ -142,7 +142,6 @@ else()
       set (CSF_OpenGlLibs "GL EGL")
     endif()
     set (CSF_OpenGlesLibs "EGL GLESv2")
-    set (CSF_dl          "dl")
     if (USE_FREETYPE)
       set (CSF_fontconfig "fontconfig")
     endif()
