--- cmake/package_config.cmake.orig	2010-01-26 22:06:42.000000000 +0300
+++ cmake/package_config.cmake	2010-01-31 05:26:15.000000000 +0300
@@ -30,11 +30,6 @@
     SET(CPACK_CMAKE_GENERATOR "Unix Makefiles")
     SET(CPACK_GENERATOR "TBZ2;TGZ")
     SET(CPACK_PACKAGE_FILE_NAME "springlobby-${SPRINGLOBBY_REV}")
-	IF( EXISTS ${springlobby_BINARY_DIR}/config.h )
-		INSTALL(FILES
-			${springlobby_BINARY_DIR}/config.h
-			DESTINATION . OPTIONAL)
-	ENDIF( EXISTS ${springlobby_BINARY_DIR}/config.h )
 ENDIF (WIN32)
 SET(CPACK_INSTALL_CMAKE_PROJECTS "${CMAKE_BINARY_DIR};${CMAKE_PROJECT_NAME};ALL;/")
 # SET(CPACK_OUTPUT_CONFIG_FILE "/home/andy/vtk/CMake-bin/CPackConfig.cmake")
@@ -65,4 +60,4 @@
 "^${springlobby_SOURCE_DIR}/m4/"
 "^${springlobby_SOURCE_DIR}/obj/"
 )
-INCLUDE(CPack)
\ No newline at end of file
+INCLUDE(CPack)
