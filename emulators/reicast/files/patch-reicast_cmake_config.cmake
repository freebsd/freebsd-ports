--- reicast/cmake/config.cmake.orig	2020-08-21 20:26:50 UTC
+++ reicast/cmake/config.cmake
@@ -106,11 +106,13 @@ endif()
 #		AMD64/x86_64:x64, i*86:x86, ppc/powerpc[64][b|l]e:ppc[64] etc 
 #
 if(("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "i686") OR
+   ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "i386") OR
    ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "X86"))   # todo: check MATCHES "i.86" ?
   set(host_arch "x86")
   set(HOST_CPU ${CPU_X86})
 #
 elseif(("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "AMD64") OR
+       ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "amd64") OR
        ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64") OR
        ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x64"))
   set(host_arch "x64")
