BFD linker (unlike LLD) drops libm with --as-needed.
https://bugs.llvm.org/show_bug.cgi?id=32279

--- runtime/cmake/LibompHandleFlags.cmake.orig	2019-07-12 21:45:36 UTC
+++ runtime/cmake/LibompHandleFlags.cmake
@@ -158,11 +158,11 @@ function(libomp_get_libflags libflags)
   if(${IA32})
     libomp_append(libflags_local -lirc_pic LIBOMP_HAVE_IRC_PIC_LIBRARY)
   endif()
-  if(${CMAKE_SYSTEM_NAME} MATCHES "DragonFly")
+  if(${CMAKE_SYSTEM_NAME} MATCHES "DragonFly|FreeBSD")
     libomp_append(libflags_local "-Wl,--no-as-needed" LIBOMP_HAVE_AS_NEEDED_FLAG)
     libomp_append(libflags_local "-lm")
     libomp_append(libflags_local "-Wl,--as-needed" LIBOMP_HAVE_AS_NEEDED_FLAG)
-  elseif(${CMAKE_SYSTEM_NAME} MATCHES "(Free|Net)BSD")
+  elseif(${CMAKE_SYSTEM_NAME} MATCHES "NetBSD")
     libomp_append(libflags_local -lm)
   endif()
   set(libflags_local ${libflags_local} ${LIBOMP_LIBFLAGS})
