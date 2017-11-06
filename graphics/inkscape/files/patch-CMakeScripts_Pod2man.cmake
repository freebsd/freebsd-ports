--- CMakeScripts/Pod2man.cmake.orig	2017-01-06 16:19:54.351838000 +0100
+++ CMakeScripts/Pod2man.cmake	2017-01-06 16:20:26.957487000 +0100
@@ -48,7 +48,7 @@
         )
         install(
             FILES ${MANFILE_FULL}
-            DESTINATION ${CMAKE_INSTALL_PREFIX}/${SHARE_INSTALL}/man/man${SECTION}
+            DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man${SECTION}
         )
     endif()
 endmacro(pod2man PODFILE NAME SECTION CENTER)
