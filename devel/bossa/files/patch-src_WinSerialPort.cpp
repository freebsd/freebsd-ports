--- src/WinSerialPort.cpp.orig	2017-03-31 15:31:35 UTC
+++ src/WinSerialPort.cpp
@@ -251,3 +251,15 @@ WinSerialPort::flush()
 {
     Sleep(1);
 }
+
+void
+WinSerialPort::setDTR(bool dtr)
+{
+    Sleep(1);
+}
+
+void
+WinSerialPort::setRTS(bool rts)
+{
+    Sleep(1);
+}
