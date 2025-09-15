--- Modules/FindBoost.cmake.orig	2024-11-06 13:41:37 UTC
+++ Modules/FindBoost.cmake
@@ -140,6 +140,9 @@ This module reads hints about search locations from va
 ``BOOST_LIBRARYDIR``
   Preferred library directory e.g. ``<prefix>/lib``.
 
+``BOOST_PYTHON_SUFFIX``
+  Preferred Python version.
+
 ``Boost_NO_SYSTEM_PATHS``
   Set to ``ON`` to disable searching in locations not
   specified by these hint variables. Default is ``OFF``.
@@ -574,6 +577,9 @@ endfunction()
   endif()
 endfunction()
 
+# https://gitlab.kitware.com/cmake/cmake/issues/18865
+set(Boost_NO_BOOST_CMAKE ON CACHE BOOL "Disable the search for boost-cmake")
+
 #-------------------------------------------------------------------------------
 # Before we go searching, check whether a boost cmake package is available, unless
 # the user specifically asked NOT to search for one.
@@ -2170,7 +2177,7 @@ if(Boost_VERSION_STRING AND Boost_FIND_COMPONENTS)
 # On versions < 1.35, remove the System library from the considered list
 # since it wasn't added until 1.35.
 if(Boost_VERSION_STRING AND Boost_FIND_COMPONENTS)
-  if(Boost_VERSION_STRING VERSION_LESS 1.35.0)
+  if(Boost_VERSION_STRING VERSION_LESS 1.35.0 OR Boost_VERSION_STRING VERSION_GREATER_EQUAL 1.71.0)
     list(REMOVE_ITEM Boost_FIND_COMPONENTS system)
   endif()
 endif()
@@ -2196,10 +2202,10 @@ foreach(COMPONENT ${Boost_FIND_COMPONENTS})
   # Handle Python version suffixes
   unset(COMPONENT_PYTHON_VERSION_MAJOR)
   unset(COMPONENT_PYTHON_VERSION_MINOR)
-  if(${COMPONENT} MATCHES "^(python|mpi_python|numpy)([0-9])\$")
+  if(${COMPONENT}${BOOST_PYTHON_SUFFIX} MATCHES "^(python|mpi_python|numpy)([0-9])\$")
     set(COMPONENT_UNVERSIONED "${CMAKE_MATCH_1}")
     set(COMPONENT_PYTHON_VERSION_MAJOR "${CMAKE_MATCH_2}")
-  elseif(${COMPONENT} MATCHES "^(python|mpi_python|numpy)([0-9])\\.?([0-9]+)\$")
+  elseif(${COMPONENT}${BOOST_PYTHON_SUFFIX} MATCHES "^(python|mpi_python|numpy)([0-9]+)\$")
     set(COMPONENT_UNVERSIONED "${CMAKE_MATCH_1}")
     set(COMPONENT_PYTHON_VERSION_MAJOR "${CMAKE_MATCH_2}")
     set(COMPONENT_PYTHON_VERSION_MINOR "${CMAKE_MATCH_3}")
