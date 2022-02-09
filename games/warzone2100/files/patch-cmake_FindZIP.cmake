--- cmake/FindZIP.cmake.orig	2021-04-18 18:28:41 UTC
+++ cmake/FindZIP.cmake
@@ -29,8 +29,8 @@ set(_PF32BIT "ProgramFiles(x86)")
 #
 
 # Search for 7-Zip
-find_program(ZIP_EXECUTABLE NAMES 7z 7za PATHS "$ENV{ProgramFiles}/7-Zip" "$ENV{${_PF32BIT}}/7-Zip" "$ENV{ProgramW6432}/7-Zip")
-if(ZIP_EXECUTABLE MATCHES "7z|7za")
+find_program(ZIP_EXECUTABLE NAMES 7zz REQUIRED)
+if(ZIP_EXECUTABLE MATCHES "7zz")
 	# Test whether 7-Zip supports the "-bb0" option to disable log output
 	execute_process(COMMAND ${ZIP_EXECUTABLE} i -bb0
 					RESULT_VARIABLE 7z_bb_result
@@ -110,7 +110,7 @@ function(COMPRESS_ZIP)
 		message( FATAL_ERROR "Unsupported compression level \"${_parsedArguments_COMPRESSION_LEVEL}\" (must be: 0, 1, 3, 5, 7, 9)" )
 	endif()
 
-	if(ZIP_EXECUTABLE MATCHES "7z|7za")
+	if(ZIP_EXECUTABLE MATCHES "7zz")
 		set(_zipExecutableOptions a -tzip -mtc=off)
 		if(DEFINED _parsedArguments_COMPRESSION_LEVEL)
 			# 7z command-line option for compression level (when in ZIP mode) is: "-mx=#"
