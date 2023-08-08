--- src/Samba.cpp.orig	2023-02-13 04:05:19 UTC
+++ src/Samba.cpp
@@ -141,7 +141,7 @@ Samba::connect(SerialPort::Ptr port, int bps)
 bool
 Samba::connect(SerialPort::Ptr port, int bps)
 {
-    _port = move(port);
+    _port = std::move(port);
 
     // Try to connect at a high speed if USB
     _isUsb = _port->isUsb();
