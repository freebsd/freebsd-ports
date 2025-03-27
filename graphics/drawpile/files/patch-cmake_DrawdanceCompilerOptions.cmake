--- cmake/DrawdanceCompilerOptions.cmake.orig	2025-03-26 05:46:04 UTC
+++ cmake/DrawdanceCompilerOptions.cmake
@@ -44,7 +44,7 @@ else()
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
