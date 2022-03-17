--- rts/build/cmake/UtilVersion.cmake.orig	2022-01-10 23:00:52 UTC
+++ rts/build/cmake/UtilVersion.cmake
@@ -183,7 +183,7 @@ macro (fetch_spring_version dir prefix)
 		# Try to fetch version through VERSION file
 		get_version_from_file(${prefix}_VERSION "${dir}/VERSION")
 		if (${${prefix}_VERSION-NOTFOUND})
-			message (FATAL_ERROR "Failed to fetch ${prefix} version.")
+			message (FATAL_ERROR "Failed to fetch ${prefix} version from ${dir}/VERSION.")
 		else ()
 			message (STATUS "${prefix} version fetched from VERSION file: ${${prefix}_VERSION}")
 		endif ()
