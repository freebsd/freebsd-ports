--- ./src/ftpserver/vsftpdmonitor.h.orig	2010-06-12 01:33:45.000000000 +0400
+++ ./src/ftpserver/vsftpdmonitor.h	2010-06-15 22:33:09.875079873 +0400
@@ -53,7 +53,7 @@
 // 			else
 // 				mFtpWhoCommand.bin = whoPath + "ps";
 
-			mFtpWhoCommand.args << "-fe";
+			mFtpWhoCommand.args << "-ax -ouid,pid,ppid,cpu,start,tty,time,command";
 
 /*			if (useSudo==true)
 			{
