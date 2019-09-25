--- projects/openmp/runtime/cmake/LibompHandleFlags.cmake.orig
+++ projects/openmp/runtime/cmake/LibompHandleFlags.cmake
@@ -158,11 +158,11 @@
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
