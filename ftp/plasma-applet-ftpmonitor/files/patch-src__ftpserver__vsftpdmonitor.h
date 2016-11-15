--- src/ftpserver/vsftpdmonitor.h.orig	2010-06-11 21:33:45 UTC
+++ src/ftpserver/vsftpdmonitor.h
@@ -53,7 +53,7 @@ class VsftpdMonitor : public FTPMonitorL
 // 			else
 // 				mFtpWhoCommand.bin = whoPath + "ps";
 
-			mFtpWhoCommand.args << "-fe";
+			mFtpWhoCommand.args << "-ax -ouid,pid,ppid,cpu,start,tty,time,command";
 
 /*			if (useSudo==true)
 			{
