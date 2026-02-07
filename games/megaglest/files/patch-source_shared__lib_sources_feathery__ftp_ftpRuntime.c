--- source/shared_lib/sources/feathery_ftp/ftpRuntime.c.orig	2020-08-25 07:57:08 UTC
+++ source/shared_lib/sources/feathery_ftp/ftpRuntime.c
@@ -30,6 +30,13 @@
 #include "ftp.h"
 #include "ftpMessages.h"
 
+int VERBOSE_MODE_ENABLED;
+
+ftpFindExternalFTPServerIpType ftpFindExternalFTPServerIp;
+ftpAddUPNPPortForwardType              ftpAddUPNPPortForward;
+ftpRemoveUPNPPortForwardType   ftpRemoveUPNPPortForward;
+ftpIsValidClientType            ftpIsValidClient;
+ftpIsClientAllowedToGetFileType ftpIsClientAllowedToGetFile;
 
 /**
  * @brief server-sockets that listens for incoming connections
