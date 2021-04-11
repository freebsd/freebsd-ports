--- cmake/modules/FindOpenVDB.cmake.orig	2021-01-11 13:01:51 UTC
+++ cmake/modules/FindOpenVDB.cmake
@@ -326,24 +326,24 @@ macro(just_fail msg)
   return()
 endmacro()
 
-find_package(IlmBase QUIET COMPONENTS Half)
-if(NOT IlmBase_FOUND)
-  pkg_check_modules(IlmBase QUIET IlmBase)
+find_package(Imath QUIET COMPONENTS Half)
+if(NOT Imath_FOUND)
+  pkg_check_modules(Imath QUIET Imath)
 endif()
-if (IlmBase_FOUND AND NOT TARGET IlmBase::Half)
-  message(STATUS "Falling back to IlmBase found by pkg-config...")
+if (Imath_FOUND AND NOT TARGET Imath::Half)
+  message(STATUS "Falling back to Imath found by pkg-config...")
 
-  find_library(IlmHalf_LIBRARY NAMES Half)
-  if(IlmHalf_LIBRARY-NOTFOUND OR NOT IlmBase_INCLUDE_DIRS)
-    just_fail("IlmBase::Half can not be found!")
+  find_library(Imath_LIBRARY NAMES Imath)
+  if(Imath_LIBRARY-NOTFOUND OR NOT Imath_INCLUDE_DIRS)
+    just_fail("Imath::Half can not be found!")
   endif()
   
-  add_library(IlmBase::Half UNKNOWN IMPORTED)
-  set_target_properties(IlmBase::Half PROPERTIES
-    IMPORTED_LOCATION "${IlmHalf_LIBRARY}"
-    INTERFACE_INCLUDE_DIRECTORIES "${IlmBase_INCLUDE_DIRS}")
-elseif(NOT IlmBase_FOUND)
-  just_fail("IlmBase::Half can not be found!")
+  add_library(Imath::Half UNKNOWN IMPORTED)
+  set_target_properties(Imath::Half PROPERTIES
+    IMPORTED_LOCATION "${Imath_LIBRARY}"
+    INTERFACE_INCLUDE_DIRECTORIES "${Imath_INCLUDE_DIRS}")
+elseif(NOT Imath_FOUND)
+  just_fail("Imath::Half can not be found!")
 endif()
 find_package(TBB ${_quiet} ${_required} COMPONENTS tbb)
 find_package(ZLIB ${_quiet} ${_required})
@@ -430,7 +430,7 @@ if(OpenVDB_USES_LOG4CPLUS)
 endif()
 
 if(OpenVDB_USES_ILM)
-  find_package(IlmBase ${_quiet} ${_required})
+  find_package(Imath ${_quiet} ${_required})
 endif()
 
 if(OpenVDB_USES_EXR)
@@ -442,7 +442,7 @@ if(UNIX)
 endif()
 
 # Set deps. Note that the order here is important. If we're building against
-# Houdini 17.5 we must include OpenEXR and IlmBase deps first to ensure the
+# Houdini 17.5 we must include OpenEXR and Imath deps first to ensure the
 # users chosen namespaced headers are correctly prioritized. Otherwise other
 # include paths from shared installs (including houdini) may pull in the wrong
 # headers
@@ -450,7 +450,7 @@ endif()
 set(_OPENVDB_VISIBLE_DEPENDENCIES
   Boost::iostreams
   Boost::system
-  IlmBase::Half
+  Imath::Half
 )
 
 set(_OPENVDB_DEFINITIONS)
@@ -460,10 +460,10 @@ endif()
 
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
