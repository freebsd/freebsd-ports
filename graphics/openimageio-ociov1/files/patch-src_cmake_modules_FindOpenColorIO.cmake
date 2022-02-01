--- src/cmake/modules/FindOpenColorIO.cmake.orig	2021-12-08 14:45:20 UTC
+++ src/cmake/modules/FindOpenColorIO.cmake
@@ -14,21 +14,22 @@ include (FindPackageHandleStandardArgs)
 include (FindPackageMessage)
 
 find_path (OPENCOLORIO_INCLUDE_DIR
-    OpenColorIO/OpenColorIO.h
+    OpenColorIOv1/OpenColorIO.h
     HINTS
         ${OPENCOLORIO_INCLUDE_PATH}
         ENV OPENCOLORIO_INCLUDE_PATH
     PATHS
+        /usr/local/include
         /sw/include
         /opt/local/include
-    DOC "The directory where OpenColorIO/OpenColorIO.h resides")
+    DOC "The directory where OpenColorIOv1/OpenColorIO.h resides")
 
-if (EXISTS "${OPENCOLORIO_INCLUDE_DIR}/OpenColorIO/OpenColorABI.h")
+if (EXISTS "${OPENCOLORIO_INCLUDE_DIR}/OpenColorIOv1/OpenColorABI.h")
     # Search twice, because this symbol changed between OCIO 1.x and 2.x
-    file(STRINGS "${OPENCOLORIO_INCLUDE_DIR}/OpenColorIO/OpenColorABI.h" TMP
+    file(STRINGS "${OPENCOLORIO_INCLUDE_DIR}/OpenColorIOv1/OpenColorABI.h" TMP
          REGEX "^#define OCIO_VERSION_STR[ \t].*$")
     if (NOT TMP)
-        file(STRINGS "${OPENCOLORIO_INCLUDE_DIR}/OpenColorIO/OpenColorABI.h" TMP
+        file(STRINGS "${OPENCOLORIO_INCLUDE_DIR}/OpenColorIOv1/OpenColorABI.h" TMP
              REGEX "^#define OCIO_VERSION[ \t].*$")
     endif ()
     string (REGEX MATCHALL "([0-9]+)\\.([0-9]+)\\.[0-9]+" OPENCOLORIO_VERSION ${TMP})
@@ -38,8 +39,8 @@ endif ()
 
 find_library (OPENCOLORIO_LIBRARY
     NAMES
-        OpenColorIO
-        OpenColorIO_${OPENCOLORIO_VERSION_MAJOR}_${OPENCOLORIO_VERSION_MINOR}
+        OpenColorIOv1
+        OpenColorIO_1_1
     HINTS
         ${OPENCOLORIO_LIBRARY_PATH}
         ENV OPENCOLORIO_LIBRARY_PATH
