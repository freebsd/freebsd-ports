
$FreeBSD$

--- NetSocket.cpp.orig
+++ NetSocket.cpp
@@ -45,7 +45,7 @@
 namespace CodeWorker {
 	bool socketReaderCBK(ScpStream& theStream, void* pData) {
 		char tcBuffer[2048];
-		int hSocket = (int) pData;
+		int hSocket = (intptr_t) pData;
 		int iLength = recv(hSocket, tcBuffer, 2047, 0);
 		if (iLength <= 0) return false;
 		theStream.writeBinaryData(tcBuffer, iLength);
@@ -53,7 +53,7 @@
 	}
 
 	bool socketWriterCBK(ScpStream& theStream, void* pData) {
-		int hSocket = (int) pData;
+		int hSocket = (intptr_t) pData;
 		int iLength = theStream.size();
 		if (iLength <= 0) return false;
 		return NetSocket::sendToSocket(hSocket, theStream.readBuffer(), iLength);
