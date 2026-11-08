--- src/ifd/base/messages/Discovery.cpp.orig	2025-10-21 08:00:00 UTC
+++ src/ifd/base/messages/Discovery.cpp
@@ -267,9 +267,21 @@ void Discovery::setAddresses(const QSet<QHostAddress>& pAddresses)
 			continue;
 		}
 
+		// FreeBSD defaults to net.inet6.ip6.v6only=1, so a connect() to an
+		// IPv4-mapped IPv6 address (e.g. the sender of an IPv4 broadcast
+		// received on a dual-stack socket) fails with EINVAL, which Qt
+		// reports as ConnectionRefusedError. Use the plain IPv4 address.
+		auto host = address;
+		bool isIPv4 = false;
+		const quint32 ipv4 = address.toIPv4Address(&isIPv4);
+		if (isIPv4 && address.protocol() == QAbstractSocket::IPv6Protocol)
+		{
+			host = QHostAddress(ipv4);
+		}
+
 		QUrl url;
 		url.setScheme(QStringLiteral("wss"));
-		url.setHost(address.toString());
+		url.setHost(host.toString());
 		url.setPort(mPort);
 		mAddresses << url;
 	}
