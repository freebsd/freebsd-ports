--- src/uptimesensor.cpp.orig  Wed Aug 27 01:32:14 2003
+++ src/uptimesensor.cpp       Wed Aug 27 02:34:41 2003
@@ -7,6 +7,11 @@
  *   the Free Software Foundation; either version 2 of the License, or     *
  *   (at your option) any later version.                                   *
  ***************************************************************************/
+#ifdef __FreeBSD__
+#include <sys/time.h>
+#include <sys/sysctl.h>
+#endif
+
 #include "uptimesensor.h"
 
 UptimeSensor::UptimeSensor( int interval ) : Sensor( interval )
@@ -16,6 +21,42 @@
 
 void UptimeSensor::update()
 {
+#ifdef __FreeBSD__
+      struct timeval  boottime;
+      time_t          now;            /* the current time of day */
+
+      double avenrun[3];
+      time_t uptime;
+      int days, hours, i, mins, secs;
+      int mib[2];
+      size_t size;
+      char buf[256];
+
+        /*
+         * Get time of day.
+         */
+        (void)time(&now);
+
+        /*
+         * Determine how long system has been up.
+         * (Found by looking getting "boottime" from the kernel)
+         */
+        mib[0] = CTL_KERN;
+        mib[1] = KERN_BOOTTIME;
+        size = sizeof(boottime);
+        if (sysctl(mib, 2, &boottime, &size, NULL, 0) != -1 &&
+            boottime.tv_sec != 0) {
+                uptime = now - boottime.tv_sec;
+                if (uptime > 60)
+                        uptime += 30;
+                days = uptime / 86400;
+                uptime %= 86400;
+                hours = uptime / 3600;
+                uptime %= 3600;
+                mins = uptime / 60;
+                secs = uptime % 60;
+        }
+#else
     QFile file("/proc/uptime");
     QString line;
     if ( file.open(IO_ReadOnly | IO_Translate) )
@@ -35,7 +76,7 @@
         int mins = uptime / 60;
         uptime -= mins * 60;
         int secs = uptime;
-
+#endif
 
         QString format;
         SensorParams *sp;
@@ -63,5 +104,7 @@
             meter->setValue(format);
             ++it;
         }
+#ifndef __FreeBSD__
     }
+#endif
 }
