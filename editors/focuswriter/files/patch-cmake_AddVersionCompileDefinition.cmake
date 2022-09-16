--- cmake/AddVersionCompileDefinition.cmake.orig	2022-09-01 14:29:17 UTC
+++ cmake/AddVersionCompileDefinition.cmake
@@ -3,9 +3,6 @@ function(add_version_compile_definition versionstr_fil
 # SPDX-License-Identifier: GPL-3.0-or-later
 
 function(add_version_compile_definition versionstr_file versionstr_def)
-	# Use project's VERSION by default
-	set(versionstr ${PROJECT_VERSION})
-
 	find_package(Git QUIET)
 	if(Git_FOUND)
 		# Find git repository
@@ -38,6 +35,11 @@ function(add_version_compile_definition versionstr_fil
 				)
 			endif()
 		endif()
+	endif()
+
+	# Fall back to project's VERSION
+	if ("${versionstr}" STREQUAL "")
+		set(versionstr ${PROJECT_VERSION})
 	endif()
 
 	# Pass version as compile definition to file
