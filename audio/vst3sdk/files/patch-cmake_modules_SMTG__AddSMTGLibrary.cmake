- workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=254489

--- cmake/modules/SMTG_AddSMTGLibrary.cmake.orig	2021-12-16 12:29:25 UTC
+++ cmake/modules/SMTG_AddSMTGLibrary.cmake
@@ -126,7 +126,7 @@ function(smtg_target_create_link_to_plugin target dest
         add_custom_command(
             TARGET ${target} POST_BUILD
             COMMAND mkdir -p "${TARGET_DESTINATION}"
-            COMMAND ln -svfF "${TARGET_SOURCE}" "${TARGET_DESTINATION}"
+            COMMAND ln -sv "${TARGET_SOURCE}" "${TARGET_DESTINATION}"
         )
     endif(SMTG_WIN)
 endfunction(smtg_target_create_link_to_plugin)
