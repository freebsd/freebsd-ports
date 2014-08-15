--- common/Socket_unix.cpp
+++ common/Socket_unix.cpp
@@ -18,7 +18,7 @@
 #include "common/Strings.h"
 
 #define BUFSIZE 512
-#if defined(_MACOSX) && !defined(SOCK_CLOEXEC)
+#if (defined(_MACOSX) || defined (__FreeBSD__)) && !defined(SOCK_CLOEXEC)
 	#define SOCK_CLOEXEC 0
 #endif
 
@@ -130,8 +130,10 @@ std::wstring Socket::read(int timeout) {
 
 void Socket::stopReadWait() {
 	TelldusCore::MutexLocker locker(&d->mutex);
-	d->connected = false;
-	// TODO(stefan): somehow signal the socket here?
+	if(d->connected && d->socket != -1) {
+		d->connected = false;
+		shutdown(d->socket, SHUT_RDWR);
+	}
 }
 
 void Socket::write(const std::wstring &msg) {
