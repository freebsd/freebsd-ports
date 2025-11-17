--- core/backends/lan/lanlinkprovider.cpp.orig	2025-11-01 18:19:03 UTC
+++ core/backends/lan/lanlinkprovider.cpp
@@ -427,6 +427,7 @@ void LanLinkProvider::encrypted()
 
     NetworkPacket *identityPacket = m_receivedIdentityPackets[socket].np;
 
+    QString deviceId = identityPacket->get<QString>(QStringLiteral("deviceId"));
     int protocolVersion = identityPacket->get<int>(QStringLiteral("protocolVersion"), -1);
     if (protocolVersion >= 8) {
         disconnect(socket, &QObject::destroyed, nullptr, nullptr);
@@ -435,7 +436,7 @@ void LanLinkProvider::encrypted()
         NetworkPacket myIdentity = KdeConnectConfig::instance().deviceInfo().toIdentityPacket();
         socket->write(myIdentity.serialize());
         socket->flush();
-        connect(socket, &QIODevice::readyRead, this, [this, socket, protocolVersion]() {
+        connect(socket, &QIODevice::readyRead, this, [this, socket, protocolVersion, deviceId]() {
             if (!socket->canReadLine()) {
                 // This can happen if the packet is large enough to be split in two chunks
                 return;
@@ -452,6 +453,12 @@ void LanLinkProvider::encrypted()
             int newProtocolVersion = secureIdentityPacket->get<int>(QStringLiteral("protocolVersion"), 0);
             if (newProtocolVersion != protocolVersion) {
                 qCWarning(KDECONNECT_CORE) << "Protocol version changed half-way through the handshake:" << protocolVersion << "->" << newProtocolVersion;
+                return;
+            }
+            QString newDeviceId = secureIdentityPacket->get<QString>(QStringLiteral("deviceId"));
+            if (newDeviceId != deviceId) {
+                qCWarning(KDECONNECT_CORE) << "Device ID changed half-way through the handshake:" << deviceId << "->" << newDeviceId;
+                return;
             }
             DeviceInfo deviceInfo = DeviceInfo::FromIdentityPacketAndCert(*secureIdentityPacket, socket->peerCertificate());
 
