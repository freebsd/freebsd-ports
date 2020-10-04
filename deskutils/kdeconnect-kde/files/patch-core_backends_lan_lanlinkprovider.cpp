--- core/backends/lan/lanlinkprovider.cpp.cve   2020-10-04 08:10:12.704397000 +0200
+++ core/backends/lan/lanlinkprovider.cpp       2020-10-04 08:12:38.587533000 +0200
@@ -229,6 +229,17 @@
             continue;
         }

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

         if (m_receivedIdentityPackets.size() > MAX_REMEMBERED_IDENTITY_PACKETS) {
