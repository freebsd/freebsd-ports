--- src/ftpmonitorloop.cpp.orig	2010-06-12 06:18:35 UTC
+++ src/ftpmonitorloop.cpp
@@ -84,7 +84,7 @@ QString FTPMonitorLoop::getExecutedFtpWh
 bool FTPMonitorLoop::ftpdServerIsRunning(QString ftpdServerName)
 {
 	QProcess checkFtpd;
-	checkFtpd.start( "pidof " + ftpdServerName );
+	checkFtpd.start( "pgrep " + ftpdServerName );
 	
 	if (!checkFtpd.waitForStarted())
 		return true;
