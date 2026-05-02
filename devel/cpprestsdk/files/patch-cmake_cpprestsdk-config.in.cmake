--- cmake/cpprestsdk-config.in.cmake.orig	2023-12-05 04:23:31 UTC
+++ cmake/cpprestsdk-config.in.cmake
@@ -17,7 +17,7 @@ if(@CPPREST_USES_BOOST@)
 
 if(@CPPREST_USES_BOOST@)
   if(UNIX)
-    find_dependency(Boost COMPONENTS random system thread filesystem chrono atomic date_time regex)
+    find_dependency(Boost COMPONENTS random thread filesystem chrono atomic date_time regex)
   else()
     find_dependency(Boost COMPONENTS system date_time regex)
   endif()
