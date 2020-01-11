--- config/LibraryDefine.cmake.orig	2019-09-18 01:02:06 UTC
+++ config/LibraryDefine.cmake
@@ -100,8 +100,6 @@ function(ILMBASE_DEFINE_LIBRARY libname)
   if(BUILD_SHARED_LIBS AND (NOT "${ILMBASE_LIB_SUFFIX}" STREQUAL ""))
     set(verlibname ${CMAKE_SHARED_LIBRARY_PREFIX}${libname}${ILMBASE_LIB_SUFFIX}${CMAKE_SHARED_LIBRARY_SUFFIX})
     set(baselibname ${CMAKE_SHARED_LIBRARY_PREFIX}${libname}${CMAKE_SHARED_LIBRARY_SUFFIX})
-    install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_INSTALL_FULL_LIBDIR} ${CMAKE_COMMAND} -E create_symlink ${verlibname} ${baselibname})")
-    install(CODE "message(\"-- Creating symlink in ${CMAKE_INSTALL_FULL_LIBDIR} ${baselibname} -> ${verlibname}\")")
     set(verlibname)
     set(baselibname)
   endif()
