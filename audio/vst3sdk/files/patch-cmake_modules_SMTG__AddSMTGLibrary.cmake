- workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=254489

--- cmake/modules/SMTG_AddSMTGLibrary.cmake.orig	2021-03-22 20:48:43 UTC
+++ cmake/modules/SMTG_AddSMTGLibrary.cmake
@@ -109,7 +109,7 @@ function(smtg_create_link_to_plugin target)
         add_custom_command(
             TARGET ${target} POST_BUILD
             COMMAND mkdir -p "${TARGET_DESTINATION}"
-            COMMAND ln -svfF "${TARGET_SOURCE}" "${TARGET_DESTINATION}"
+            COMMAND ln -sv "${TARGET_SOURCE}" "${TARGET_DESTINATION}"
         )
     endif()
 endfunction()
