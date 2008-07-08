--- lib/guestApp/guestApp.c.orig	2008-05-29 10:42:37.000000000 +0300
+++ lib/guestApp/guestApp.c	2008-05-29 10:43:09.000000000 +0300
@@ -77,7 +77,7 @@
 #elif defined(_WIN32)
 #define GUESTAPP_TOOLS_INSTALL_PATH ""
 #else
-#define GUESTAPP_TOOLS_INSTALL_PATH "/etc/vmware-tools"
+#define GUESTAPP_TOOLS_INSTALL_PATH "/usr/local/share/vmware-tools"
 #endif
 
 /*
