--- ./src/ftpserver/pureftpdmonitor.h.orig	2010-06-12 01:33:45.000000000 +0400
+++ ./src/ftpserver/pureftpdmonitor.h	2010-08-28 02:58:47.738230460 +0400
@@ -50,7 +50,7 @@
 		void createExecCommand(bool useSudo,QString whoPath)
 		{
 			if (whoPath=="")
-				mFtpWhoCommand.bin  = "/usr/sbin/" + ftpWhoBinaryName();
+				mFtpWhoCommand.bin  = "/usr/local/sbin/" + ftpWhoBinaryName();
 			else
 				mFtpWhoCommand.bin = whoPath + ftpWhoBinaryName();
 
@@ -101,7 +101,7 @@
 		 */
 		QString ftpdServerName()
 		{
-			return QString("pureftpd");
+			return QString("pure-ftpd");
 		}
 
 		QString static ftpWhoBinaryName()
