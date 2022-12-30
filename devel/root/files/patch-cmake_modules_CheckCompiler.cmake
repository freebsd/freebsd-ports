--- cmake/modules/CheckCompiler.cmake.orig	2022-11-16 10:35:46 UTC
+++ cmake/modules/CheckCompiler.cmake
@@ -202,7 +202,7 @@ endif()
 
 
 #---Setup details depending on the major platform type----------------------------------------------
-if(CMAKE_SYSTEM_NAME MATCHES Linux)
+if(CMAKE_SYSTEM_NAME MATCHES Linux OR CMAKE_SYSTEM_NAME MATCHES FreeBSD)
   include(SetUpLinux)
 elseif(APPLE)
   include(SetUpMacOS)
