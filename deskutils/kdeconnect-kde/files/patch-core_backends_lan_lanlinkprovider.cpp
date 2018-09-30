--- core/backends/lan/lanlinkprovider.cpp.orig	2018-05-30 21:41:03 UTC
+++ core/backends/lan/lanlinkprovider.cpp
@@ -196,6 +196,17 @@ void LanLinkProvider::newUdpConnection() //udpBroadcas
 
         int tcpPort = receivedPacket->get<int>(QStringLiteral("tcpPort"));
 
+        // convert IPv6 addresses of type "v4-mapped" to IPv4 
+        QHostAddress addr = sender;
+        if (addr.protocol() == QAbstractSocket::IPv6Protocol) {
+            bool success;
+            QHostAddress convertedAddr = QHostAddress(addr.toIPv4Address(&success));
+            if (success) {
+                // qCDebug(KDECONNECT_CORE) << "Converting IPv6" << addr << "to IPv4" << convertedAddr;
+                sender = convertedAddr;
+            }
+        }
+
         //qCDebug(KDECONNECT_CORE) << "Received Udp identity packet from" << sender << " asking for a tcp connection on port " << tcpPort;
 
         QSslSocket* socket = new QSslSocket(this);
