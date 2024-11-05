--- lib/guestApp/guestApp.c.orig	2024-10-10 15:05:07 UTC
+++ lib/guestApp/guestApp.c
@@ -65,7 +65,7 @@
 #elif defined __APPLE__
 #   define GUESTAPP_TOOLS_INSTALL_PATH "/Library/Application Support/VMware Tools"
 #else
-#   define GUESTAPP_TOOLS_INSTALL_PATH "/etc/vmware-tools"
+#   define GUESTAPP_TOOLS_INSTALL_PATH "%%PREFIX%%/share/vmware-tools"
 #endif
 
 #if defined _WIN32
