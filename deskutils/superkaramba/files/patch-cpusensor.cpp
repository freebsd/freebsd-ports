--- src/cpusensor.cpp.orig     Mon Apr 21 15:17:03 2003
+++ src/cpusensor.cpp  Wed Aug 27 16:27:57 2003
@@ -8,6 +8,14 @@
  *   (at your option) any later version.                                   *
  ***************************************************************************/
 
+#ifdef __FreeBSD__
+#include <sys/time.h>
+#include <sys/dkstat.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/resource.h>
+#endif
+
 #include "cpusensor.h"
 
 CPUSensor::CPUSensor( QString cpu, int interval ) : Sensor( interval )
@@ -24,6 +32,19 @@
 
 void CPUSensor::getTicks (long &u,long &s,long &n,long &i)
 {
+#ifdef __FreeBSD__
+      static long cp_time[CPUSTATES];
+
+        size_t size = sizeof(cp_time);
+
+      /* get the cp_time array */
+      if (sysctlbyname("kern.cp_time", &cp_time, &size, NULL, 0) != -1) {
+              u = cp_time[CP_USER];
+              s = cp_time[CP_SYS] + cp_time[CP_INTR];
+              n = cp_time[CP_NICE];
+              i = cp_time[CP_IDLE];
+      }
+#else
     QFile file("/proc/stat");
     QString line;
     if ( file.open(IO_ReadOnly | IO_Translate) )
@@ -46,6 +67,7 @@
         i = rx.cap(4).toLong();
         file.close();
     }
+#endif
     else
     {
         u = 0;
@@ -53,7 +75,6 @@
         n = 0;
         i = 0;
     }
-
 }
 
 int CPUSensor::getCPULoad()
