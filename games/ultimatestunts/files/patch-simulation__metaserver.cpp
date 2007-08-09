--- ./simulation/metaserver.cpp.orig	2007-08-09 21:50:18.000000000 +0400
+++ ./simulation/metaserver.cpp	2007-08-09 22:02:25.000000000 +0400
@@ -186,13 +186,15 @@
 
 bool CMetaServer::httpPost(const CString &args, const CString &data)
 {
+	char datalength[20];
+	sprintf(datalength, "%ld", data.length());
 	CString postdata =
 		CString("POST ") + m_URI+args + " HTTP/1.1\r\n"
 		"Host: " + m_Hostname + "\r\n"
 		"Connection: close\r\n"
 		"User-Agent: " + PACKAGE + "/" + VERSION + "\r\n"
 		"Content-Type: application/x-www-form-urlencoded\r\n"
-		"Content-Length: " + data.length() + "\r\n"
+		"Content-Length: " + datalength + "\r\n"
 		"\r\n"
 		+ data + "\r\n";
 
