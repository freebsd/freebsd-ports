--- cmake/SimutransInstall.cmake.orig	2024-07-20 16:43:38 UTC
+++ cmake/SimutransInstall.cmake
@@ -38,7 +38,6 @@ if (SIMUTRANS_UPDATE_LANGFILES)
 		# MSVC has no variable on the install target path at execution time, which is why we expand the directories at creation time!
 		install(CODE "execute_process(COMMAND powershell -ExecutionPolicy Bypass -File ${CMAKE_SOURCE_DIR}/tools/get_lang_files.ps1 WORKING_DIRECTORY ${SIMUTRANS_OUTPUT_DIR}/${SIMUTRANS_BASE_DIR}/..)")
 	else ()
-		install(CODE "execute_process(COMMAND sh ${CMAKE_SOURCE_DIR}/tools/get_lang_files.sh WORKING_DIRECTORY ${SIMUTRANS_OUTPUT_DIR}/${SIMUTRANS_BASE_DIR}/.. )")
 	endif ()
 endif ()
 
@@ -46,12 +45,6 @@ if (NOT WIN32)
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
@@ -129,4 +122,4 @@ if (SIMUTRANS_STEAM_BUILT)
 	elseif(UNIX AND NOT APPLE) # For Apple it was already done in MacBundle.cmake
 		install(FILES  ${CMAKE_SOURCE_DIR}/sdk/redistributable_bin/linux64/libsteam_api.so DESTINATION ${CMAKE_BINARY_DIR}/simutrans/lib)
 	endif()
-endif()
\ No newline at end of file
+endif()
