- workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=254489

--- cmake/modules/SMTG_AddSMTGLibrary.cmake.orig	2024-07-26 07:55:28 UTC
+++ cmake/modules/SMTG_AddSMTGLibrary.cmake
@@ -131,7 +131,7 @@ function(smtg_target_create_link_to_plugin target dest
         add_custom_command(
             TARGET ${target} POST_BUILD
             COMMAND ${CMAKE_COMMAND} -E make_directory "${TARGET_DESTINATION}"
-            COMMAND ln -svfF "${TARGET_SOURCE}" "${TARGET_DESTINATION}"
+            COMMAND ln -sv "${TARGET_SOURCE}" "${TARGET_DESTINATION}"
         )
     endif(SMTG_WIN)
 endfunction(smtg_target_create_link_to_plugin)
