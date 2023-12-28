Fix configure with CMake >= 3.28.0 where the FindFreetype module uses
freetype-config.cmake if found, which already defines the freetype
target.
 
--- lib/freetype.cmake.orig	2023-11-03 16:14:29 UTC
+++ lib/freetype.cmake
@@ -1,7 +1,7 @@
 
-add_library(freetype INTERFACE)
-
 if(PLATFORM_WINDOWS OR PLATFORM_MAC)
+	add_library(freetype INTERFACE)
+
 	# We use prebuilt binaries for windows and mac
 	get_prebuilt_path(PREBUILT_PATH)
 	set(FREETYPE_ROOT_DIR "${PREBUILT_PATH}/freetype")
@@ -21,6 +21,10 @@ else()
 
 else()
 	find_package(Freetype REQUIRED)
+
+	if(NOT TARGET freetype)
+		add_library(freetype INTERFACE)
+	endif()
 
 	target_include_directories(freetype INTERFACE ${FREETYPE_INCLUDE_DIRS})
 	target_link_libraries(freetype INTERFACE ${FREETYPE_LIBRARIES})
