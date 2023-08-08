--- Modules/GNUInstallDirs.cmake.orig	2023-03-27 21:42:13 UTC
+++ Modules/GNUInstallDirs.cmake
@@ -408,6 +408,12 @@ macro(GNUInstallDirs_get_absolute_install_dir absvar v
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
