--- main/httpd.cc.orig	Thu Apr  6 04:01:41 2006
+++ main/httpd.cc	Mon Apr 10 13:47:47 2006
@@ -580,8 +580,9 @@
 };
 
 SocketPtr tHttpDownload::export_ctrl_socket(){
+	SocketPtr rval;
 	if (HTTP) return(HTTP->export_ctrl_socket());
-	return(SocketPtr());
+	return rval;
 };
 
 tHttpDownload::~tHttpDownload() {
