--- cmake/install_macros.cmake.orig	2021-04-22 20:14:44 UTC
+++ cmake/install_macros.cmake
@@ -362,8 +362,8 @@ FUNCTION(INSTALL_DEBUG_TARGET target)
         CONFIGURATIONS Release RelWithDebInfo
         COMPONENT ${ARG_COMPONENT}
         OPTIONAL)
-    ENDIF()
-  ENDFOREACH()
+    ENDFOREACH()
+  ENDIF()
 
 ENDFUNCTION()
 
