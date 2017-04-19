--- src/WinSerialPort.h.orig	2017-03-31 15:31:35 UTC
+++ src/WinSerialPort.h
@@ -55,6 +55,8 @@ class WinSerialPort : public SerialPort (public)
 
     bool timeout(int millisecs);
     void flush();
+    void setDTR(bool dtr);
+    void setRTS(bool rts);
 
 private:
     HANDLE _handle;
