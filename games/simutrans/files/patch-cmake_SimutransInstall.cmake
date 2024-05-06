--- cmake/SimutransInstall.cmake.orig	2024-05-04 14:27:27 UTC
+++ cmake/SimutransInstall.cmake
@@ -36,19 +36,12 @@ else ()
 	# MSVC has no variable on the install target path at execution time, which is why we expand the directories at creation time!
 	install(CODE "execute_process(COMMAND powershell -ExecutionPolicy Bypass -File ${CMAKE_SOURCE_DIR}/tools/get_lang_files.ps1 WORKING_DIRECTORY ${SIMUTRANS_OUTPUT_DIR}/${SIMUTRANS_BASE_DIR}/..)")
 else ()
-	install(CODE "execute_process(COMMAND sh ${CMAKE_SOURCE_DIR}/tools/get_lang_files.sh WORKING_DIRECTORY ${SIMUTRANS_OUTPUT_DIR}/${SIMUTRANS_BASE_DIR}/.. )")
 endif ()
 
 #
 # Pak installer
 #
 if (NOT WIN32)
-	install(FILES "${CMAKE_SOURCE_DIR}/tools/get_pak.sh" DESTINATION "${SIMUTRANS_BASE_DIR}"
-		PERMISSIONS
-			OWNER_READ OWNER_WRITE OWNER_EXECUTE
-			GROUP_READ GROUP_EXECUTE
-			WORLD_READ WORLD_EXECUTE
-	)
 else ()
 	# NSIS must be installed manually in the path with the right addons
 	if(MINGW)
