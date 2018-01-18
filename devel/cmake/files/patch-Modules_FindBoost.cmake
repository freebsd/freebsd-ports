Allow imported targets, even with newer Boost.

--- Modules/FindBoost.cmake.orig	2017-12-13 13:25:23 UTC
+++ Modules/FindBoost.cmake
@@ -799,7 +799,6 @@ function(_Boost_COMPONENT_DEPENDENCIES component _ret)
     endif()
     if(NOT Boost_VERSION VERSION_LESS 106600)
       message(WARNING "New Boost version may have incorrect or missing dependencies and imported targets")
-      set(_Boost_IMPORTED_TARGETS FALSE)
     endif()
   endif()
 
