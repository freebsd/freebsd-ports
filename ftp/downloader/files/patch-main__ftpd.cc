--- main/ftpd.cc.orig	Thu Apr  6 04:02:36 2006
+++ main/ftpd.cc	Mon Apr 10 13:48:42 2006
@@ -662,8 +662,9 @@
 };
 
 SocketPtr tFtpDownload::export_ctrl_socket(){
+	SocketPtr rval;
 	if (FTP) return(FTP->export_ctrl_socket());
-	return(SocketPtr());
+	return rval;
 };
 
 tFtpDownload::~tFtpDownload() {
