--- cmake/modules/FindOpenVDB.cmake.orig	2025-04-10 11:26:51 UTC
+++ cmake/modules/FindOpenVDB.cmake
@@ -347,24 +347,12 @@ endmacro()
   return()
 endmacro()
 
-find_package(IlmBase QUIET)
-if(NOT IlmBase_FOUND)
-  pkg_check_modules(IlmBase QUIET IlmBase)
+find_package(Imath QUIET COMPONENTS Imath)
+if(NOT Imath_FOUND)
+  pkg_check_modules(Imath QUIET Imath)
 endif()
-if (IlmBase_FOUND AND NOT TARGET IlmBase::Half)
-  message(STATUS "Falling back to IlmBase found by pkg-config...")
-
-  find_library(IlmHalf_LIBRARY NAMES Half)
-  if(IlmHalf_LIBRARY-NOTFOUND OR NOT IlmBase_INCLUDE_DIRS)
-    just_fail("IlmBase::Half can not be found!")
-  endif()
-  
-  add_library(IlmBase::Half UNKNOWN IMPORTED)
-  set_target_properties(IlmBase::Half PROPERTIES
-    IMPORTED_LOCATION "${IlmHalf_LIBRARY}"
-    INTERFACE_INCLUDE_DIRECTORIES "${IlmBase_INCLUDE_DIRS}")
-elseif(NOT IlmBase_FOUND)
-  just_fail("IlmBase::Half can not be found!")
+if(NOT Imath_FOUND)
+  just_fail("Imath::Half can not be found!")
 endif()
 find_package(TBB ${_quiet} ${_required} COMPONENTS tbb)
 find_package(ZLIB ${_quiet} ${_required})
@@ -451,7 +439,7 @@ if(OpenVDB_USES_ILM)
 endif()
 
 if(OpenVDB_USES_ILM)
-  find_package(IlmBase ${_quiet} ${_required})
+  find_package(Imath ${_quiet} ${_required})
 endif()
 
 if(OpenVDB_USES_EXR)
@@ -463,7 +451,7 @@ endif()
 endif()
 
 # Set deps. Note that the order here is important. If we're building against
-# Houdini 17.5 we must include OpenEXR and IlmBase deps first to ensure the
+# Houdini 17.5 we must include OpenEXR and Imath deps first to ensure the
 # users chosen namespaced headers are correctly prioritized. Otherwise other
 # include paths from shared installs (including houdini) may pull in the wrong
 # headers
@@ -471,7 +459,7 @@ set(_OPENVDB_VISIBLE_DEPENDENCIES
 set(_OPENVDB_VISIBLE_DEPENDENCIES
   Boost::iostreams
   Boost::system
-  IlmBase::Half
+  Imath::Imath
 )
 
 set(_OPENVDB_DEFINITIONS)
@@ -481,10 +469,10 @@ if(OpenVDB_USES_EXR)
 
 if(OpenVDB_USES_EXR)
   list(APPEND _OPENVDB_VISIBLE_DEPENDENCIES
-    IlmBase::IlmThread
-    IlmBase::Iex
-    IlmBase::Imath
-    OpenEXR::IlmImf
+    OpenEXR::IlmThread
+    OpenEXR::Iex
+    Imath::Imath
+    OpenEXR::OpenEXR
   )
   list(APPEND _OPENVDB_DEFINITIONS "-DOPENVDB_TOOLS_RAYTRACER_USE_EXR")
 endif()
