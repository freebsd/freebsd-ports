--- cmake/modules/PkgConfigEx.cmake.orig	2017-06-02 14:39:21 UTC
+++ cmake/modules/PkgConfigEx.cmake
@@ -85,6 +85,6 @@ macro(add_pkgconfig_file _input _output)
 	)
 
 	install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${_output}
-		DESTINATION ${LIB_INSTALL_DIR}/pkgconfig
+		DESTINATION ${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig
 	)
 endmacro()
