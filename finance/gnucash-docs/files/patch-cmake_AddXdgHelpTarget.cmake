--- cmake/AddXdgHelpTarget.cmake.orig	2023-09-05 01:13:47 UTC
+++ cmake/AddXdgHelpTarget.cmake
@@ -45,8 +45,8 @@ function (add_xdghelp_target targetbase lang entities 
       COMMAND ${CMAKE_COMMAND} -E make_directory "${BUILD_DIR}/figures"
 
       # Add links to make our documentation visible for KDE's help system
-      COMMAND ${CMAKE_COMMAND} -E make_directory "${BUILD_DIR_KDE_BASE}/${kde_lang}"
-      COMMAND ${CMAKE_COMMAND} -E create_symlink "${BUILD_DIR}" "${BUILD_DIR_KDE_BASE}/${kde_lang}/${docname}"
+      # COMMAND ${CMAKE_COMMAND} -E make_directory "${BUILD_DIR_KDE_BASE}/${kde_lang}"
+      # COMMAND ${CMAKE_COMMAND} -E create_symlink "${BUILD_DIR}" "${BUILD_DIR_KDE_BASE}/${kde_lang}/${docname}"
       COMMAND touch "${CMAKE_CURRENT_BINARY_DIR}/xdghelptrigger")
 
 
@@ -91,8 +91,8 @@ function (add_xdghelp_target targetbase lang entities 
 
     # Add links to make our documentation visible for KDE's help system
     set(doc_install_dir_kde_base "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATADIR}/doc/HTML")
-    install(CODE "execute_process (COMMAND ${CMAKE_COMMAND} -E make_directory \"${doc_install_dir_kde_base}\")"
-        COMPONENT "xdghelp")
-    install(CODE "execute_process (COMMAND ${CMAKE_COMMAND} -E create_symlink \"../../../${doc_install_dir_base}\" \"${doc_install_dir_kde_base}/${kde_lang}\")"
-        COMPONENT "xdghelp")
+    # install(CODE "execute_process (COMMAND ${CMAKE_COMMAND} -E make_directory \"${doc_install_dir_kde_base}\")"
+    #    COMPONENT "xdghelp")
+    # install(CODE "execute_process (COMMAND ${CMAKE_COMMAND} -E create_symlink \"../../../${doc_install_dir_base}\" \"${doc_install_dir_kde_base}/${kde_lang}\")"
+    #    COMPONENT "xdghelp")
 endfunction()
