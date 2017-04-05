--- src/libirc/ServerConnection.cpp.orig	2017-04-05 11:23:15 UTC
+++ src/libirc/ServerConnection.cpp
@@ -322,7 +322,7 @@ bool ServerConnection::sendVersion(const ustring& to)
     ustring r("");
     ustring m("");
     #endif
-    ustring vstring("LostIRC "VERSION" on " + s + " " + r + " [" + m + "]");
+    ustring vstring("LostIRC " VERSION" on " + s + " " + r + " [" + m + "]");
     ustring msg("NOTICE " + to + " :\001VERSION " + vstring + "\001\r\n");
 
     return _socket.send(msg);
