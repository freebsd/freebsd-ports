--- CMakeScripts/Pod2man.cmake.orig	2020-05-01 13:17:41 UTC
+++ CMakeScripts/Pod2man.cmake
@@ -34,13 +34,13 @@ macro(pod2man PODFILE_FULL RELEASE SECTION CENTER)
             set(MANFILE_TEMP "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${LANG}.tmp")
             set(MANFILE_FULL "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${LANG}.${SECTION}")
             set(MANFILE_FULL_GZ "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${LANG}.${SECTION}.gz")
-            set(MANFILE_DEST "${SHARE_INSTALL}/man/${LANG}/man${SECTION}")
+            set(MANFILE_DEST "${CMAKE_INSTALL_PREFIX}/man/${LANG}/man${SECTION}")
         else()
             set(MANPAGE_TARGET "man-${NAME}")
             set(MANFILE_TEMP "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.tmp")
             set(MANFILE_FULL "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${SECTION}")
             set(MANFILE_FULL_GZ "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${SECTION}.gz")
-            set(MANFILE_DEST "${SHARE_INSTALL}/man/man${SECTION}")
+            set(MANFILE_DEST "${CMAKE_INSTALL_PREFIX}/man/man${SECTION}")
         endif()
         add_custom_command(
             OUTPUT ${MANFILE_TEMP}
