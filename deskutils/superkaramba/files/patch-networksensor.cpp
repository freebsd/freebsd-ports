--- src/networksensor.cpp.orig	Mon Apr 21 15:17:03 2003
+++ src/networksensor.cpp	Sun Nov  9 18:34:35 2003
@@ -7,14 +7,65 @@
  *   the Free Software Foundation; either version 2 of the License, or     *
  *   (at your option) any later version.                                   *
  ***************************************************************************/
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/socket.h>
+#include <net/route.h>
+#endif
+
 #include "networksensor.h"
 
 NetworkSensor::NetworkSensor( QString dev, int interval ):Sensor( interval )
 {
    device = dev.lower();
+
+#ifdef __FreeBSD__
+   /* Determine number of interfaces */
+   u_int   n    = 0;
+   size_t  nlen = 0;
+   nlen = sizeof(n);
+   sysctlbyname("net.link.generic.system.ifcount", &n, &nlen, NULL, 0);
+
+   size_t  if_miblen = 0;
+   if_miblen = sizeof(if_mib);
+   static  int name[] = { CTL_NET,
+                          PF_LINK,
+                          NETLINK_GENERIC,
+                          IFMIB_IFDATA,
+                          0,
+                          IFDATA_GENERAL };
+
+   /* 
+      If the device was defined by the theme, find the right devicenumber.
+      If not, use the device that holds the default route.
+    */
+
+   if_number = -1;
+   int if_gw = -1;
+
+   for (int i = 1; i <= n; ++i) {
+      name[4] = i;
+      /* Get data for iface-number i */
+      sysctl(name, 6, (void*)&if_mib, (size_t*)&if_miblen, (void*)NULL, (size_t)0);
+
+      /* We found the right interface? */
+      if (QString(if_mib.ifmd_name) == device) {
+         if_number = i;
+         break;
+      }
+
+      /* Does the interface hold the default route? */
+      if ( if_mib.ifmd_flags & RTF_GATEWAY )
+         if_gw = i;
+   }
+
+   if ((if_number == -1) && (if_gw != -1))
+      if_number = if_gw;
+#else
    if( device == "" )
    	device = "eth0";
-
+#endif
      getInOutBytes(receivedBytes,transmittedBytes);
     netTimer.start();
 
@@ -24,6 +75,27 @@
 }
 void NetworkSensor::getInOutBytes ( unsigned long &in,unsigned long &out) const
 {
+#ifdef __FreeBSD__
+    if (if_number != -1) {
+       size_t  if_miblen = 0;
+       if_miblen = sizeof(if_mib);
+       int name[] = { CTL_NET,
+                      PF_LINK,
+                      NETLINK_GENERIC,
+                      IFMIB_IFDATA,
+                      if_number,
+                      IFDATA_GENERAL };
+
+       sysctl(name, 6, (void*)&if_mib, (size_t*)&if_miblen, (void*)NULL, (size_t)0);
+
+       in = if_mib.ifmd_data.ifi_ibytes;
+       out = if_mib.ifmd_data.ifi_obytes;
+   }
+   else {
+      in = 0;
+      out = 0;
+   }
+#else
     QFile file("/proc/net/dev");
     QString line;
     if ( file.open(IO_ReadOnly | IO_Translate) )
@@ -49,6 +121,7 @@
         }
     file.close();
     }
+#endif
 }
 
 void NetworkSensor::update()
