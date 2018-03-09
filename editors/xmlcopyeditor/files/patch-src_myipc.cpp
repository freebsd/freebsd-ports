--- src/myipc.cpp.orig	2017-09-04 09:59:48 UTC
+++ src/myipc.cpp
@@ -46,7 +46,7 @@ wxConnectionBase *MyServer::OnAcceptConn
 
 MyServerConnection::MyServerConnection()
 	: wxConnection()
-	, mFrameWnd ( ( wxIntPtr ) NULL )
+	, mFrameWnd (0)
 {
 	server_connection = this;
 }
