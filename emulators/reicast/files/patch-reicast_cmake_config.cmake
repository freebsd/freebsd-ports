--- reicast/cmake/config.cmake.orig	2020-10-18 11:22:48 UTC
+++ reicast/cmake/config.cmake
@@ -39,6 +39,7 @@ set(OS_LINUX       0x10000002)
 set(OS_DARWIN      0x10000003)
 set(OS_IOS         0x10000004)  # todo: iOS != OS_DARWIN
 set(OS_ANDROID     0x10000005)  # todo: should be SYSTEM_ANDROID but ! OS_LINUX
+set(OS_FREEBSD     0x10000006)
 
 set(OS_UWP         0x10000011)
 set(OS_NSW_HOS     0x80000001)
@@ -106,11 +107,13 @@ endif()
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
@@ -164,6 +167,9 @@ elseif("windowsstore" STREQUAL "${host_os}")
 
 elseif(CMAKE_HOST_WIN32)
   set(HOST_OS ${OS_WINDOWS}) 
+
+elseif("freebsd" STREQUAL "${host_os}")
+  set(HOST_OS ${OS_FREEBSD}) 
 
 elseif(CMAKE_HOST_APPLE)
 
