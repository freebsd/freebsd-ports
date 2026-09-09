--- cmake/add_install_rules.cmake.orig	2026-08-26 12:24:41 UTC
+++ cmake/add_install_rules.cmake
@@ -18,7 +18,9 @@ function(add_install_rules)
 
     # System manual page
     install(FILES "docs/dosbox.1"
-      DESTINATION "${INSTALL_DIR_MAN}/man1")
+      DESTINATION "${INSTALL_DIR_MAN}/man1"
+      RENAME "dosbox-staging.1"
+      )
 
     # Application menu entry
     install(FILES "extras/linux/${INSTALL_ICON_NAME}.desktop"
@@ -41,7 +43,7 @@ function(add_install_rules)
     endforeach()
 
     # Bundle the resources
-    install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE_COPY_PATH}"
+    install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE_COPY_PATH}/"
             DESTINATION "${INSTALL_DIR_RESOURCES}")
 
     # Bundle required licenses
