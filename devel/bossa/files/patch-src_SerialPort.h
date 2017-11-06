--- src/SerialPort.h.orig	2017-03-31 15:31:35 UTC
+++ src/SerialPort.h
@@ -68,6 +68,8 @@ class SerialPort (public)
 
     virtual bool timeout(int millisecs) = 0;
     virtual void flush() = 0;
+    virtual void setDTR(bool dtr) = 0;
+    virtual void setRTS(bool rts) = 0;
 
     virtual std::string name() const { return _name; }
 
