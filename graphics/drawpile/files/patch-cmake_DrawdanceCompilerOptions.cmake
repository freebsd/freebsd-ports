--- cmake/DrawdanceCompilerOptions.cmake.orig	2024-01-14 11:12:43 UTC
+++ cmake/DrawdanceCompilerOptions.cmake
@@ -32,7 +32,7 @@ else()
         $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
         $<$<COMPILE_LANGUAGE:C>:-Wstrict-prototypes>
     )
-	if(UNIX AND NOT APPLE)
-		add_compile_definitions(_XOPEN_SOURCE=600)
-	endif()
+	#if(UNIX AND NOT APPLE)
+	#	add_compile_definitions(_XOPEN_SOURCE=600)
+	#endif()
 endif()
