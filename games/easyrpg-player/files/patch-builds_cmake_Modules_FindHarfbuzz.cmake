--- builds/cmake/Modules/FindHarfbuzz.cmake.orig	2020-08-13 08:40:25 UTC
+++ builds/cmake/Modules/FindHarfbuzz.cmake
@@ -55,7 +55,13 @@ if(HARFBUZZ_FOUND)
 
 	if(NOT TARGET Harfbuzz::Harfbuzz)
 		add_library(Harfbuzz::Harfbuzz UNKNOWN IMPORTED)
-		find_library(Freetype REQUIRED)
+		# Handle circular dependency: FindFreetype.cmake asks
+		# for a QUIET lookup.
+		if (Harfbuzz_FIND_QUIETLY)
+			find_library(Freetype QUIET)
+		else()
+			find_library(Freetype REQUIRED)
+		endif()
 		set_target_properties(Harfbuzz::Harfbuzz PROPERTIES
 			INTERFACE_INCLUDE_DIRECTORIES "${HARFBUZZ_INCLUDE_DIRS}"
 			INTERFACE_LINK_LIBRARIES Freetype::Freetype
