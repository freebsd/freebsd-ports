--- Onboard/Config.py.orig	2025-07-03 16:13:44 UTC
+++ Onboard/Config.py
@@ -106,8 +106,8 @@ START_ONBOARD_XEMBED_COMMAND = "onboard --xid"
 
 START_ONBOARD_XEMBED_COMMAND = "onboard --xid"
 
-INSTALL_DIR                = "/usr/share/onboard"
-LOCAL_INSTALL_DIR          = "/usr/local/share/onboard"
+INSTALL_DIR                = "%%LOCALBASE%%/share/onboard"
+LOCAL_INSTALL_DIR          = "%%LOCALBASE%%/share/onboard"
 USER_DIR                   = "onboard"
 
 SYSTEM_DEFAULTS_FILENAME   = "onboard-defaults.conf"
