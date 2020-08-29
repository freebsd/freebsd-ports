--- cmake/FindSIP.cmake.orig	2020-08-28 05:25:49 UTC
+++ cmake/FindSIP.cmake
@@ -40,8 +40,12 @@ ELSE(SIP_VERSION)
     STRING(REGEX REPLACE ".*\nsip_version_str:([^\n]+).*$" "\\1" SIP_VERSION_STR ${sip_config})
     STRING(REGEX REPLACE ".*\nsip_bin:([^\n]+).*$" "\\1" SIP_BINARY_PATH ${sip_config})
     STRING(REGEX REPLACE ".*\ndefault_sip_dir:([^\n]+).*$" "\\1" SIP_DEFAULT_SIP_DIR ${sip_config})
-    STRING(REGEX REPLACE ".*\nsip_inc_dir:([^\n]+).*$" "\\1" SIP_INCLUDE_DIR ${sip_config})
-    STRING(REGEX REPLACE ".*\nsip_module_dir:([^\n]+).*$" "\\1" SIP_MODULE_DIR ${sip_config})
+    IF(${SIP_VERSION_STR} VERSION_LESS 5)
+      STRING(REGEX REPLACE ".*\nsip_inc_dir:([^\n]+).*$" "\\1" SIP_INCLUDE_DIR ${sip_config})
+      STRING(REGEX REPLACE ".*\nsip_module_dir:([^\n]+).*$" "\\1" SIP_MODULE_DIR ${sip_config})
+    ELSE(${SIP_VERSION_STR} VERSION_LESS 5)
+      FIND_PROGRAM(SIP_MODULE_EXECUTABLE sip-module)
+    ENDIF(${SIP_VERSION_STR} VERSION_LESS 5)
     SET(SIP_FOUND TRUE)
   ENDIF(sip_config)
 
