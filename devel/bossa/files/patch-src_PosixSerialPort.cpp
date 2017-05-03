--- src/PosixSerialPort.cpp.orig	2017-03-31 15:31:35 UTC
+++ src/PosixSerialPort.cpp
@@ -85,6 +85,9 @@ PosixSerialPort::open(int baud,
 
     switch (baud)
     {
+    case 1200:
+        speed = B1200;
+        break;
     case 9600:
         speed = B9600;
         break;
@@ -297,6 +300,34 @@ PosixSerialPort::timeout(int millisecs)
 {
     _timeout = millisecs;
     return true;
+}
+
+void
+PosixSerialPort::setDTR(bool dtr)
+{
+    if (_devfd == -1)
+        return;
+
+    int iFlags = TIOCM_DTR;
+
+    if (dtr)
+        ioctl(_devfd, TIOCMBIS, &iFlags);
+    else
+        ioctl(_devfd, TIOCMBIC, &iFlags);
+}
+
+void
+PosixSerialPort::setRTS(bool rts)
+{
+    if (_devfd == -1)
+        return;
+
+    int iFlags = TIOCM_RTS;
+
+    if (rts)
+        ioctl(_devfd, TIOCMBIS, &iFlags);
+    else
+        ioctl(_devfd, TIOCMBIC, &iFlags);
 }
 
 void
