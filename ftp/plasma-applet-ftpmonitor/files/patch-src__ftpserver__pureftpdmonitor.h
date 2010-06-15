--- ./src/ftpserver/pureftpdmonitor.h.orig	2010-06-12 01:33:45.000000000 +0400
+++ ./src/ftpserver/pureftpdmonitor.h	2010-06-15 22:44:35.632390428 +0400
@@ -50,7 +50,7 @@
 		void createExecCommand(bool useSudo,QString whoPath)
 		{
 			if (whoPath=="")
-				mFtpWhoCommand.bin  = "/usr/sbin/" + ftpWhoBinaryName();
+				mFtpWhoCommand.bin  = "/usr/local/sbin/" + ftpWhoBinaryName();
 			else
 				mFtpWhoCommand.bin = whoPath + ftpWhoBinaryName();
 
