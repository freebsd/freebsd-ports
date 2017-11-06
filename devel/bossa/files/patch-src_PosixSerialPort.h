--- src/PosixSerialPort.h.orig	2017-03-31 15:31:35 UTC
+++ src/PosixSerialPort.h
@@ -52,6 +52,8 @@ class PosixSerialPort : public SerialPort (public)
 
     bool timeout(int millisecs);
     void flush();
+    void setDTR(bool dtr);
+    void setRTS(bool rts);
     void setAutoFlush(bool autoflush);
 
 private:
