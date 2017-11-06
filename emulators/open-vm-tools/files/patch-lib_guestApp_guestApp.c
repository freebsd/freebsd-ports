--- lib/guestApp/guestApp.c.orig	2017-02-24 22:15:37 UTC
+++ lib/guestApp/guestApp.c
@@ -63,7 +63,7 @@
 #elif defined __APPLE__
 #   define GUESTAPP_TOOLS_INSTALL_PATH "/Library/Application Support/VMware Tools"
 #else
-#   define GUESTAPP_TOOLS_INSTALL_PATH "/etc/vmware-tools"
+#   define GUESTAPP_TOOLS_INSTALL_PATH "%%PREFIX%%/share/vmware-tools"
 #endif
 
 #if defined _WIN32
