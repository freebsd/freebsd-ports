--- share/cmake/OCIOMacros.cmake.orig	2019-03-28 05:12:57 UTC
+++ share/cmake/OCIOMacros.cmake
@@ -96,27 +96,6 @@ MACRO(OCIOFindOpenImageIO)
         set(OIIO_FOUND TRUE)
         message(STATUS "Found OIIO library ${OIIO_LIBRARIES}")
         message(STATUS "Found OIIO includes ${OIIO_INCLUDES}")
-
-        # Unfortunately, OIIO hides a dependency to Ilmbase includes
-
-        if(ILMBASE_PATH)
-            message(STATUS "Ilmbase path explicitly specified: ${ILMBASE_PATH}")
-        endif()
-
-        FIND_PATH( ILMBASE_INCLUDES OpenEXR/half.h
-            ${ILMBASE_PATH}/include/
-            /usr/include
-            /usr/local/include
-            /sw/include
-            /opt/local/include
-            DOC "The directory where OpenEXR/half.h resides")
-
-        if(ILMBASE_INCLUDES)
-            message(STATUS "Found Ilmbase includes ${ILMBASE_INCLUDES}")
-        else()
-            set(OIIO_FOUND FALSE)
-            message(STATUS "Ilmbase not found. Specify ILMBASE_PATH to locate it")
-        endif()
     else()
         set(OIIO_FOUND FALSE)
         message(STATUS "OIIO not found. Specify OIIO_PATH to locate it")
@@ -222,7 +201,7 @@ MACRO(OCIOFindPython)
         file(TO_CMAKE_PATH "${PYTHON_LIBRARY_DIRS_RAW}" PYTHON_LIBRARY_DIRS)
 
         FIND_LIBRARY(PYTHON_LIBRARY
-            NAMES "python${PYTHON_VERSION}"
+            NAMES "${PYTHON_VERSION}${PYTHON_ABIVER}"
             PATHS ${PYTHON_LIBRARY_DIRS}
             NO_DEFAULT_PATH # Don't be "helpful" and randomly grab library from /usr/lib etc
         )
