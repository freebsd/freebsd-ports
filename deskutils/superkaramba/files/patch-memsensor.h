--- src/memsensor.h.orig       Mon Apr 21 15:17:03 2003
+++ src/memsensor.h    Fri Sep  5 12:08:46 2003
@@ -12,6 +12,12 @@
 #include "sensor.h"
 #include <qstring.h>
 #include <qregexp.h>
+#ifdef __FreeBSD__
+#include <kprocess.h>
+#include <kprocio.h>
+#include <kvm.h>
+#include <osreldate.h>
+#endif
 
 class MemSensor :  public Sensor
 {
@@ -36,6 +42,26 @@
 private:
   QString meminfo;
   void readValues();
+#ifdef __FreeBSD__
+  int pageshift;           /* log base 2 of the pagesize */
+  QString sensorResult;
+  int swapTotal;
+  int swapUsed;
+
+# if __FreeBSD_version < 500018
+  KShellProcess ksp;
+  bool MaxSet;
+
+# else
+  kvm_t *kd;
+  kvm_swap swapinfo;
+# endif
+
+private slots:
+    void receivedStdout(KProcess *, char *buffer, int);
+    void processExited(KProcess *);
+
+#endif
 };
 
 #endif // MEMSENSOR_H
