--- src/ftpserver/ncftpdmonitor.h.orig	2010-06-11 21:33:45 UTC
+++ src/ftpserver/ncftpdmonitor.h
@@ -55,7 +55,7 @@ class NcftpdMonitor : public FTPMonitorL
 		void createExecCommand(bool useSudo,QString whoPath)
 		{
 			if (whoPath=="")
-				mFtpWhoCommand.bin = "/usr/local/sbin/" + ftpWhoBinaryName();
+				mFtpWhoCommand.bin = "/usr/local/bin/" + ftpWhoBinaryName();
 			else
 				mFtpWhoCommand.bin = whoPath + ftpWhoBinaryName();
 
