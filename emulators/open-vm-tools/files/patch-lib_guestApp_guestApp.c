--- lib/guestApp/guestApp.c.orig	2025-06-19 04:05:18 UTC
+++ lib/guestApp/guestApp.c
@@ -65,7 +65,7 @@
 #elif defined __APPLE__
 #   define GUESTAPP_TOOLS_INSTALL_PATH "/Library/Application Support/VMware Tools"
 #else
-#   define GUESTAPP_TOOLS_INSTALL_PATH "/etc/vmware-tools"
+#   define GUESTAPP_TOOLS_INSTALL_PATH "%%PREFIX%%/share/vmware-tools"
 #endif
 
 #if defined _WIN32
