--- Sources/Network/setupnetwork_unix.cpp.orig	Sun Mar 14 02:04:13 2004
+++ Sources/Network/setupnetwork_unix.cpp	Thu Jul  8 21:41:56 2004
@@ -26,7 +26,7 @@
 #include <signal.h>
 
 static int ref_count = 0;
-static sighandler_t old_handler = 0;
+static sig_t old_handler = 0;
 
 CL_SetupNetwork::CL_SetupNetwork(bool register_resources_only)
 {
