--- CMakeScripts/Pod2man.cmake.orig	2018-03-11 20:38:09 UTC
+++ CMakeScripts/Pod2man.cmake
@@ -48,7 +48,7 @@ macro(pod2man PODFILE_FULL RELEASE SECTION CENTER)
         )
         install(
             FILES ${MANFILE_FULL}
-            DESTINATION ${CMAKE_INSTALL_PREFIX}/${SHARE_INSTALL}/man/man${SECTION}
+            DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man${SECTION}
         )
     endif()
 endmacro(pod2man PODFILE NAME SECTION CENTER)
