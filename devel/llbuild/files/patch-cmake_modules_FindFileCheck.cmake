--- cmake/modules/FindFileCheck.cmake.orig	2016-11-04 00:07:45 UTC
+++ cmake/modules/FindFileCheck.cmake
@@ -5,12 +5,12 @@
 # FILECHECK_EXECUTABLE
 
 find_program(FILECHECK_EXECUTABLE
-             NAMES FileCheck
+             NAMES FileCheck FileCheck39
              DOC "Path to 'FileCheck' executable")
 
 # Handle REQUIRED and QUIET arguments, this will also set FILECHECK_FOUND to true
 # if FILECHECK_EXECUTABLE exists.
 include(FindPackageHandleStandardArgs)
-find_package_handle_standard_args(FileCheck
+find_package_handle_standard_args(FileCheck39
                                   "Failed to locate 'FileCheck' executable"
                                   FILECHECK_EXECUTABLE)
