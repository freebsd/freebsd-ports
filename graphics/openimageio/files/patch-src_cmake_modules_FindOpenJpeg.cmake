--- src/cmake/modules/FindOpenJpeg.cmake.orig	2021-01-17 14:28:27 UTC
+++ src/cmake/modules/FindOpenJpeg.cmake
@@ -56,18 +56,21 @@ endmacro ()

 # Generic search paths
 set (OpenJpeg_include_paths
+     /usr/local/include/openjpeg-2.4
      /usr/local/include/openjpeg-2.3
      /usr/local/include/openjpeg-2.2
      /usr/local/include/openjpeg-2.1
      /usr/local/include/openjpeg-2.0
      /usr/local/include/openjpeg
      /usr/local/include
+     /usr/include/openjpeg-2.4
      /usr/include/openjpeg-2.3
      /usr/include/openjpeg-2.2
      /usr/include/openjpeg-2.1
      /usr/include/openjpeg
      /usr/include
      /opt/local/include
+     /opt/local/include/openjpeg-2.4
      /opt/local/include/openjpeg-2.3
      /opt/local/include/openjpeg-2.2
      /opt/local/include/openjpeg-2.1
@@ -88,6 +91,7 @@ if (OpenJpeg_ROOT)
        ${OpenJpeg_library_paths}
       )
   set (OpenJpeg_include_paths
+       ${OpenJpeg_ROOT}/include/openjpeg-2.4
        ${OpenJpeg_ROOT}/include/openjpeg-2.3
        ${OpenJpeg_ROOT}/include/openjpeg-2.2
        ${OpenJpeg_ROOT}/include/openjpeg-2.1
