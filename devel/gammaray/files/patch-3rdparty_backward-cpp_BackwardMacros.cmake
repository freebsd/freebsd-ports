This seems to be a mistake, the comment says "static" but check is for dynamic!
Results in libiberty not being found

--- 3rdparty/backward-cpp/BackwardMacros.cmake.orig	2021-03-22 12:20:48 UTC
+++ 3rdparty/backward-cpp/BackwardMacros.cmake
@@ -79,7 +79,7 @@ if (${STACK_DETAILS_AUTO_DETECT})
 
 		# If we attempt to link against static bfd, make sure to link its dependencies, too
 		get_filename_component(bfd_lib_ext "${LIBBFD_LIBRARIES}" EXT)
-		if (bfd_lib_ext STREQUAL ".so")
+		if (bfd_lib_ext STREQUAL ".a")
 			list(APPEND BACKWARD_LIBRARIES iberty z)
 		endif()
 
