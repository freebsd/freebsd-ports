--- connproviders/tcp/STAFTCPConnProvider.cpp.orig	2015-10-09 21:27:13 UTC
+++ connproviders/tcp/STAFTCPConnProvider.cpp
@@ -1389,15 +1389,9 @@ STAFRC_t STAFConnectionProviderConstruct
         // Assign the default locations for the files needed for a secure
         // TCP connection provider.
 
-        tcpData.serverCertificate = STAFString(configInfo.exePath) +
-            configInfo.fileSeparator + "bin" + configInfo.fileSeparator +
-             "STAFDefault.crt";
-        tcpData.serverKey = STAFString(configInfo.exePath) +
-             configInfo.fileSeparator + "bin" + configInfo.fileSeparator +
-            "STAFDefault.key";
-        tcpData.CACertificate = STAFString(configInfo.exePath) +
-            configInfo.fileSeparator + "bin" + configInfo.fileSeparator +
-            "CAList.crt";
+        tcpData.serverCertificate = "%%DATADIR%%/STAFDefault.crt";
+        tcpData.serverKey = "%%DATADIR%%/STAFDefault.key";
+        tcpData.CACertificate = "%%DATADIR%%/CAList.crt";
 #endif
         tcpData.serverSocket  = -1;
         tcpData.serverSocketIPv6 = -1;
