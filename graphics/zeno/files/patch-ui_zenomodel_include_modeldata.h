--- ui/zenomodel/include/modeldata.h.orig	2024-09-30 13:46:54 UTC
+++ ui/zenomodel/include/modeldata.h
@@ -210,6 +210,10 @@ typedef QMap<QString, SOCKET_INFO> SOCKE
 struct INPUT_SOCKET
 {
     SOCKET_INFO info;
+
+    bool operator==(const INPUT_SOCKET& rhs) const {
+        return info == rhs.info;
+    }
 };
 Q_DECLARE_METATYPE(INPUT_SOCKET)
 typedef FuckQMap<QString, INPUT_SOCKET> INPUT_SOCKETS;
@@ -220,6 +224,10 @@ struct OUTPUT_SOCKET
 {
     SOCKET_INFO info;
     QPersistentModelIndex retIdx;   //return idx by core.
+
+    bool operator==(const OUTPUT_SOCKET& rhs) const {
+        return info == rhs.info && retIdx == rhs.retIdx;
+    }
 };
 Q_DECLARE_METATYPE(OUTPUT_SOCKET)
 typedef FuckQMap<QString, OUTPUT_SOCKET> OUTPUT_SOCKETS;
