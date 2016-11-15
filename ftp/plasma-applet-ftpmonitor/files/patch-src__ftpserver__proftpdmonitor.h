--- src/ftpserver/proftpdmonitor.h.orig	2010-06-11 21:33:45 UTC
+++ src/ftpserver/proftpdmonitor.h
@@ -55,7 +55,7 @@ class ProftpdMonitor : public FTPMonitor
 		{
 
 			if (whoPath=="")
-				mFtpWhoCommand.bin = "/usr/sbin/" + ftpWhoBinaryName();
+				mFtpWhoCommand.bin = "/usr/local/bin/" + ftpWhoBinaryName();
 			else
 				mFtpWhoCommand.bin = whoPath + ftpWhoBinaryName();
 
