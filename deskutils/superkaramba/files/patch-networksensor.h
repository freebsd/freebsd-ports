--- src/networksensor.h.orig   Mon Apr 21 15:17:03 2003
+++ src/networksensor.h        Wed Aug 27 16:36:58 2003
@@ -15,6 +15,12 @@
 #include <qdatetime.h>
 #include <qfile.h>
 #include <qregexp.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <net/if.h>
+#include <net/if_mib.h>
+#endif
 
 class NetworkSensor :  public Sensor
 {
@@ -30,7 +36,10 @@
     unsigned long transmittedBytes;
     QTime netTimer;
     QString device;
-
+#ifdef __FreeBSD__
+    int if_number;
+    ifmibdata if_mib;
+#endif
     void getInOutBytes (unsigned long &in,unsigned long &out) const;
 
 };
