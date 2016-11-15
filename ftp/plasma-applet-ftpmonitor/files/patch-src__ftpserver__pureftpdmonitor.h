--- src/ftpserver/pureftpdmonitor.h.orig	2010-06-11 21:33:45 UTC
+++ src/ftpserver/pureftpdmonitor.h
@@ -50,7 +50,7 @@ class PureftpdMonitor : public FTPMonito
 		void createExecCommand(bool useSudo,QString whoPath)
 		{
 			if (whoPath=="")
-				mFtpWhoCommand.bin  = "/usr/sbin/" + ftpWhoBinaryName();
+				mFtpWhoCommand.bin  = "/usr/local/sbin/" + ftpWhoBinaryName();
 			else
 				mFtpWhoCommand.bin = whoPath + ftpWhoBinaryName();
 
@@ -101,7 +101,7 @@ class PureftpdMonitor : public FTPMonito
 		 */
 		QString ftpdServerName()
 		{
-			return QString("pureftpd");
+			return QString("pure-ftpd");
 		}
 
 		QString static ftpWhoBinaryName()
