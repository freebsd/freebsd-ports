--- ../syncthingtray/plasmoid/lib/syncthingapplet.cpp.orig	2021-07-15 09:55:51.079368000 -0400
+++ ../syncthingtray/plasmoid/lib/syncthingapplet.cpp	2021-07-15 09:56:54.332702000 -0400
@@ -226,7 +226,7 @@
     const auto systemdConsideredForReconnect
         = settings.systemd.apply(m_connection, currentConnectionConfig(), reconnectRequired).consideredForReconnect;
 #else
-    const auto systemdRelevantForReconnect = false;
+    const auto systemdConsideredForReconnect = false;
 #endif
     if (!systemdConsideredForReconnect && (reconnectRequired || !m_connection.isConnected())) {
         m_connection.reconnect();
