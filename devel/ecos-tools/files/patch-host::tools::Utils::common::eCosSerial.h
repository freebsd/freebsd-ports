--- ../ecos/host/tools/Utils/common/eCosSerial.h~	Fri Aug 25 19:32:40 2000
+++ ../ecos/host/tools/Utils/common/eCosSerial.h	Wed Aug 25 08:14:27 2004
@@ -50,7 +50,7 @@
 // This class is a host-independent interface to a serial port
 //=================================================================
 class CeCosSerial {
-    friend CeCosSocket::SSReadResult CeCosSocket::SSRead (CeCosSerial &serial,CeCosSocket &socket,void *pBuf,unsigned int nSize,unsigned int &nRead,bool *pbStop);
+    friend class CeCosSocket;
 
 public:
     enum StopBitsType { ONE_STOP_BIT, ONE_POINT_FIVE_STOP_BITS, TWO_STOP_BITS };
