--- cmake/oidn_install.cmake.orig	2020-09-11 17:36:51 UTC
+++ cmake/oidn_install.cmake
@@ -31,6 +31,7 @@ install(DIRECTORY include/OpenImageDenoise
 ## Install documentation
 ## -----------------------------------------------------------------------------
 
+if (FALSE)
 install(
   FILES
     ${PROJECT_SOURCE_DIR}/README.md
@@ -43,6 +44,7 @@ install(
   DESTINATION ${CMAKE_INSTALL_DOCDIR}
   COMPONENT lib
 )
+endif()
 
 ## -----------------------------------------------------------------------------
 ## Install dependencies: TBB
