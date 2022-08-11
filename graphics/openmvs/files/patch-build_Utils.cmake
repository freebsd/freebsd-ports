--- build/Utils.cmake.orig	2022-04-17 08:46:34 UTC
+++ build/Utils.cmake
@@ -433,6 +433,7 @@ macro(optimize_default_compiler_settings)
 			endif()
 		endif()
 	endif()
+	set(CMAKE_CXX_STANDARD 14)
 	if(CLANG AND (CMAKE_CXX_STANDARD EQUAL 11 OR CMAKE_CXX_STANDARD EQUAL 14 OR CMAKE_CXX_STANDARD EQUAL 17))
 		set(CMAKE_EXE_LINKER_FLAGS "-stdlib=libc++")
 		add_extra_compiler_option(-stdlib=libc++)
