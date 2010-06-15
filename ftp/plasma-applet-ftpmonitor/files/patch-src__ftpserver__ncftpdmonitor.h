--- ./src/ftpserver/ncftpdmonitor.h.orig	2010-06-12 01:33:45.000000000 +0400
+++ ./src/ftpserver/ncftpdmonitor.h	2010-06-15 22:44:14.585409143 +0400
@@ -55,7 +55,7 @@
 		void createExecCommand(bool useSudo,QString whoPath)
 		{
 			if (whoPath=="")
-				mFtpWhoCommand.bin = "/usr/local/sbin/" + ftpWhoBinaryName();
+				mFtpWhoCommand.bin = "/usr/local/bin/" + ftpWhoBinaryName();
 			else
 				mFtpWhoCommand.bin = whoPath + ftpWhoBinaryName();
 
