--- common/Socket_unix.cpp.orig	2014-03-31 10:30:09 UTC
+++ common/Socket_unix.cpp
@@ -12,13 +12,14 @@
 #include <fcntl.h>
 #include <math.h>
 #include <string>
+#include <cstring>
 
 #include "common/Socket.h"
 #include "common/Mutex.h"
 #include "common/Strings.h"
 
 #define BUFSIZE 512
-#if defined(_MACOSX) && !defined(SOCK_CLOEXEC)
+#if (defined(_MACOSX) || defined (__FreeBSD__)) && !defined(SOCK_CLOEXEC)
 	#define SOCK_CLOEXEC 0
 #endif
 
@@ -128,8 +129,10 @@ std::wstring Socket::read(int timeout) {
 
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
