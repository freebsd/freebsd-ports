--- cmake/CompileBoost.cmake.orig	2022-09-19 11:42:41 UTC
+++ cmake/CompileBoost.cmake
@@ -113,7 +113,7 @@ endif()
   return()
 endif()
 
-find_package(Boost 1.78.0 EXACT QUIET COMPONENTS context CONFIG PATHS ${BOOST_HINT_PATHS})
+find_package(Boost 1.78.0 COMPONENTS context CONFIG PATHS ${BOOST_HINT_PATHS})
 set(FORCE_BOOST_BUILD OFF CACHE BOOL "Forces cmake to build boost and ignores any installed boost")
 
 if(Boost_FOUND AND NOT FORCE_BOOST_BUILD)
