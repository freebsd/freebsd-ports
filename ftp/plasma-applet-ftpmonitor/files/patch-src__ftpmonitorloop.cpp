--- ./src/ftpmonitorloop.cpp.orig	2010-06-12 10:18:35.000000000 +0400
+++ ./src/ftpmonitorloop.cpp	2010-08-30 12:10:58.553618412 +0400
@@ -84,7 +84,7 @@
 bool FTPMonitorLoop::ftpdServerIsRunning(QString ftpdServerName)
 {
 	QProcess checkFtpd;
-	checkFtpd.start( "pidof " + ftpdServerName );
+	checkFtpd.start( "pgrep " + ftpdServerName );
 	
 	if (!checkFtpd.waitForStarted())
 		return true;
