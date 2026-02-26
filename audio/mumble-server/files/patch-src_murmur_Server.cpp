--- src/murmur/Server.cpp.orig	2025-10-11 18:24:04 UTC
+++ src/murmur/Server.cpp
@@ -181,6 +181,15 @@ Server::Server(int snum, QObject *p) : QThread(p) {
 			} else {
 #ifdef Q_OS_UNIX
 				int val = 0xe0;
+#ifdef __FreeBSD__
+				if (addr.ss_family == AF_INET6) {
+					if (setsockopt(sock, IPPROTO_IPV6, IPV6_TCLASS, &val, sizeof(val))) {
+						val = 0x80;
+						if (setsockopt(sock, IPPROTO_IPV6, IPV6_TCLASS, &val, sizeof(val)))
+							log(QString("Server: Failed to set IPV6_TCLASS for UDP Socket, errno = ").arg(errno));
+					}
+				} else
+#endif
 				if (setsockopt(sock, IPPROTO_IP, IP_TOS, &val, sizeof(val))) {
 					val = 0x80;
 					if (setsockopt(sock, IPPROTO_IP, IP_TOS, &val, sizeof(val)))
