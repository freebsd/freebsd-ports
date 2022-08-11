--- cmake/CompileBoost.cmake.orig	2022-04-19 01:08:48 UTC
+++ cmake/CompileBoost.cmake
@@ -113,7 +113,7 @@ endif()
   return()
 endif()
 
-find_package(Boost 1.72.0 EXACT QUIET COMPONENTS context CONFIG PATHS ${BOOST_HINT_PATHS})
+find_package(Boost 1.72.0 COMPONENTS context CONFIG PATHS ${BOOST_HINT_PATHS})
 set(FORCE_BOOST_BUILD OFF CACHE BOOL "Forces cmake to build boost and ignores any installed boost")
 
 if(Boost_FOUND AND NOT FORCE_BOOST_BUILD)
