--- Libraries/cmake/External_STEPCode.cmake.orig	2024-11-11 02:55:22 UTC
+++ Libraries/cmake/External_STEPCode.cmake
@@ -30,6 +30,11 @@ ExternalProject_Add( STEPCODE
 		-DSC_BUILD_SHARED_LIBS=${SC_SHARED}
 		-DSC_PYTHON_GENERATOR=OFF
 		-DSC_INSTALL_PREFIX:PATH=<INSTALL_DIR>
+		# Patch to avoid build failure in FBSD 15 and higher
+		PATCH_COMMAND ${CMAKE_COMMAND} -E echo "Patching files...${CMAKE_SOURCE_DIR} - ${CMAKE_BINARY_DIR}" &&
+		${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR}/STEPCODE-prefix/src/STEPCODE/src/base/judy/src/ sed -i '' -e "s/strncpy\( _buff, other._buff/strncpy\( (char *)_buff, (char *)other._buff/g" judySArray.h &&
+                ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR}/STEPCODE-prefix/src/STEPCODE/src/base/judy/src/ sed -i '' -e "s/strncpy\( _buff, other._buff/strncpy\( (char *)_buff, (char *)other._buff/g" judyS2Array.h
+	
 )
 ExternalProject_Get_Property( STEPCODE SOURCE_DIR )
 ExternalProject_Get_Property( STEPCODE BINARY_DIR )
@@ -47,4 +52,4 @@ SET( STEPCODE_BINARY_DIR ${BINARY_DIR} )
 # Consequently, force Debug so it installs in ../sc-install directory
 # instead of /usr/local/lib.
 #
-# SC's own programs fail to build with -DSC_BUILD_SHARED_LIBS=OFF
\ No newline at end of file
+# SC's own programs fail to build with -DSC_BUILD_SHARED_LIBS=OFF
