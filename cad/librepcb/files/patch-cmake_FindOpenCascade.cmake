--- cmake/FindOpenCascade.cmake.orig	2023-09-24 10:47:05 UTC
+++ cmake/FindOpenCascade.cmake
@@ -1,6 +1,3 @@
-# Specify OpenCascade libraries needed for LibrePCB
-set(OCC_LIBRARIES TKXCAF TKXDESTEP)
-
 # Add library
 add_library(open_cascade INTERFACE)
 add_library(OpenCascade::OpenCascade ALIAS open_cascade)
@@ -15,8 +12,16 @@ if(OpenCASCADE_FOUND)
 # Try to find OCCT shared library on the system
 find_package(OpenCASCADE CONFIG QUIET)
 if(OpenCASCADE_FOUND)
-  message(STATUS "Using system OpenCASCADE (OCCT)")
+  message(STATUS "Using system OpenCASCADE (OCCT ${OpenCASCADE_VERSION})")
 
+  # Specify OpenCascade libraries needed for LibrePCB
+  # https://github.com/LibrePCB/LibrePCB/issues/1315
+  if(OpenCASCADE_VERSION VERSION_GREATER_EQUAL 7.8.0)
+    set(OCC_LIBRARIES TKCAF TKDESTEP)
+  else()
+    set(OCC_LIBRARIES TKXCAF TKXDESTEP)
+  endif()
+
   # Populate target
   target_include_directories(
     open_cascade SYSTEM INTERFACE "${OpenCASCADE_INCLUDE_DIR}"
@@ -32,7 +37,10 @@ if(OCE_FOUND)
 # Try to find OCE shared library on the system
 find_package(OCE CONFIG QUIET)
 if(OCE_FOUND)
-  message(STATUS "Using system OpenCASCADE (OCE)")
+  message(STATUS "Using system OpenCASCADE (OCE ${OCE_VERSION})")
+
+  # Specify OpenCascade libraries needed for LibrePCB
+  set(OCC_LIBRARIES TKXCAF TKXDESTEP)
 
   # Populate target
   target_include_directories(
