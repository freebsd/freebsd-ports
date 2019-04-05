--- Modules/FindBoost.cmake.orig	2019-02-07 20:55:01 UTC
+++ Modules/FindBoost.cmake
@@ -56,6 +56,8 @@ This module reads hints about search locations from va
    (or BOOSTROOT)
   BOOST_INCLUDEDIR       - Preferred include directory e.g. <prefix>/include
   BOOST_LIBRARYDIR       - Preferred library directory e.g. <prefix>/lib
+  BOOST_PYTHON_SUFFIX    - Preferred Python version
+
   Boost_NO_SYSTEM_PATHS  - Set to ON to disable searching in locations not
                            specified by these hint variables. Default is OFF.
   Boost_ADDITIONAL_VERSIONS
@@ -1739,10 +1741,10 @@ foreach(COMPONENT ${Boost_FIND_COMPONENTS})
   # Handle Python version suffixes
   unset(COMPONENT_PYTHON_VERSION_MAJOR)
   unset(COMPONENT_PYTHON_VERSION_MINOR)
-  if(${COMPONENT} MATCHES "^(python|mpi_python|numpy)([0-9])\$")
+  if(${COMPONENT}${BOOST_PYTHON_SUFFIX} MATCHES "^(python|mpi_python|numpy)([0-9])\$")
     set(COMPONENT_UNVERSIONED "${CMAKE_MATCH_1}")
     set(COMPONENT_PYTHON_VERSION_MAJOR "${CMAKE_MATCH_2}")
-  elseif(${COMPONENT} MATCHES "^(python|mpi_python|numpy)([0-9])\\.?([0-9])\$")
+  elseif(${COMPONENT}${BOOST_PYTHON_SUFFIX} MATCHES "^(python|mpi_python|numpy)([0-9])\\.?([0-9])\$")
     set(COMPONENT_UNVERSIONED "${CMAKE_MATCH_1}")
     set(COMPONENT_PYTHON_VERSION_MAJOR "${CMAKE_MATCH_2}")
     set(COMPONENT_PYTHON_VERSION_MINOR "${CMAKE_MATCH_3}")
