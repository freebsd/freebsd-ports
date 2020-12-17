--- cmake/EthCompilerSettings.cmake.orig	2020-12-16 17:41:40 UTC
+++ cmake/EthCompilerSettings.cmake
@@ -53,9 +53,10 @@ if (("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU") OR ("${
 	add_compile_options(-Wimplicit-fallthrough)
 	add_compile_options(-Wsign-conversion)
 	add_compile_options(-Wconversion)
+	add_compile_options(-Qunused-arguments)
 
 	eth_add_cxx_compiler_flag_if_supported(
-		$<$<COMPILE_LANGUAGE:CXX>:-Wextra-semi>
+		-Wextra-semi
 	)
 	eth_add_cxx_compiler_flag_if_supported(-Wfinal-dtor-non-final-class)
 	eth_add_cxx_compiler_flag_if_supported(-Wnewline-eof)
