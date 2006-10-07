--- uppsrc/Web/socket.cpp.orig	Thu Oct  5 00:43:27 2006
+++ uppsrc/Web/socket.cpp	Thu Oct  5 20:33:14 2006
@@ -12,6 +12,12 @@
 {
 	NB_TIMEOUT  = 30000,
 	SOCKBUFSIZE = 65536,
+
+#ifdef PLATFORM_WIN32
+	IS_BLOCKED = SOCKERR(EWOULDBLOCK),
+#else
+	IS_BLOCKED = SOCKERR(EINPROGRESS),
+#endif
 };
 
 static bool LogSocketFlag = false;
@@ -202,7 +208,7 @@
 		return true;
 
 	int err = GetLastError();
-	if(err != SOCKERR(EWOULDBLOCK)) {
+	if(err != IS_BLOCKED) {
 		SetSockError(NFormat("connect(%s:%d)", host, port));
 		SLOG("Socket::Data::OpenClient -> connect error, returning false");
 		return false;
@@ -274,7 +280,7 @@
 #endif
 	if(res == 0)
 		is_eof = true;
-	else if(res < 0 && GetLastError() != SOCKERR(EWOULDBLOCK))
+	else if(res < 0 && GetLastError() != IS_BLOCKED)
 		SetSockError("recv");
 	return res;
 }
@@ -282,7 +288,7 @@
 int Socket::Data::Write(const void *buf, int amount)
 {
 	int res = send(socket, (const char *)buf, amount, 0);
-	if(res == 0 || res < 0 && GetLastError() != SOCKERR(EWOULDBLOCK))
+	if(res == 0 || res < 0 && GetLastError() != IS_BLOCKED)
 		SetSockError("send");
 	return res;
 }
