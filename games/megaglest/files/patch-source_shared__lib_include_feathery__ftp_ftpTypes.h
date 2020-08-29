--- source/shared_lib/include/feathery_ftp/ftpTypes.h.orig	2020-08-25 07:39:46 UTC
+++ source/shared_lib/include/feathery_ftp/ftpTypes.h
@@ -69,7 +69,7 @@ typedef uint16_t port_t;
 extern "C" {
 #endif
 
-int VERBOSE_MODE_ENABLED;
+extern int VERBOSE_MODE_ENABLED;
 
 typedef ip_t (*ftpFindExternalFTPServerIpType)(ip_t clientIp);
 typedef void (*ftpAddUPNPPortForwardType)(int internalPort, int externalPort);
@@ -77,11 +77,11 @@ typedef void (*ftpRemoveUPNPPortForwardType)(int inter
 typedef int (*ftpIsValidClientType)(ip_t clientIp);
 typedef int (*ftpIsClientAllowedToGetFileType)(ip_t clientIp, const char *username, const char *filename);
 
-ftpFindExternalFTPServerIpType	ftpFindExternalFTPServerIp;
-ftpAddUPNPPortForwardType		ftpAddUPNPPortForward;
-ftpRemoveUPNPPortForwardType	ftpRemoveUPNPPortForward;
-ftpIsValidClientType            ftpIsValidClient;
-ftpIsClientAllowedToGetFileType ftpIsClientAllowedToGetFile;
+extern ftpFindExternalFTPServerIpType	ftpFindExternalFTPServerIp;
+extern ftpAddUPNPPortForwardType		ftpAddUPNPPortForward;
+extern ftpRemoveUPNPPortForwardType	ftpRemoveUPNPPortForward;
+extern ftpIsValidClientType            ftpIsValidClient;
+extern ftpIsClientAllowedToGetFileType ftpIsClientAllowedToGetFile;
 
 #ifdef	__cplusplus
 }
