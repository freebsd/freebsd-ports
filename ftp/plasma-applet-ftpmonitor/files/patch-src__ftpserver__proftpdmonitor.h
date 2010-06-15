--- ./src/ftpserver/proftpdmonitor.h.orig	2010-06-12 01:33:45.000000000 +0400
+++ ./src/ftpserver/proftpdmonitor.h	2010-06-15 22:42:56.463724571 +0400
@@ -55,7 +55,7 @@
 		{
 
 			if (whoPath=="")
-				mFtpWhoCommand.bin = "/usr/sbin/" + ftpWhoBinaryName();
+				mFtpWhoCommand.bin = "/usr/local/bin/" + ftpWhoBinaryName();
 			else
 				mFtpWhoCommand.bin = whoPath + ftpWhoBinaryName();
 
