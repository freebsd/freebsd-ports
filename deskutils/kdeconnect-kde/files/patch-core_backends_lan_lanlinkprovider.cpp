--- core/backends/lan/lanlinkprovider.cpp.orig	2023-12-18 22:14:59 UTC
+++ core/backends/lan/lanlinkprovider.cpp
@@ -291,6 +291,16 @@ void LanLinkProvider::udpBroadcastReceived()
         m_lastConnectionTime[deviceId] = now;
 
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
         if (tcpPort < MIN_TCP_PORT || tcpPort > MAX_TCP_PORT) {
             qCDebug(KDECONNECT_CORE) << "TCP port outside of kdeconnect's range";
             delete receivedPacket;
