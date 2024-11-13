--- Modules/GNUInstallDirs.cmake.orig	2024-11-06 13:41:37 UTC
+++ Modules/GNUInstallDirs.cmake
@@ -418,6 +418,12 @@ macro(GNUInstallDirs_get_absolute_install_dir absvar v
       else()
         set(${absvar} "${CMAKE_INSTALL_PREFIX}/${${var}}")
       endif()
+    elseif(CMAKE_SYSTEM_NAME MATCHES "^FreeBSD$")
+      if("${GGAID_dir}" STREQUAL "LOCALSTATEDIR")
+        set(${absvar} "/${${var}}")
+      else()
+        set(${absvar} "${CMAKE_INSTALL_PREFIX}/${${var}}")
+      endif()
     else()
       set(${absvar} "${CMAKE_INSTALL_PREFIX}/${${var}}")
     endif()
