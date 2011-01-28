--- include/gammu-datetime.h.orig	2011-01-19 10:33:05.000000000 +0300
+++ include/gammu-datetime.h	2011-01-28 14:00:45.206537651 +0300
@@ -17,6 +17,14 @@
 #include <gammu-statemachine.h>
 
 /**
+ * Checkup if the XSI POSIX extension, daylight, is not
+ * declared in <time.h>
+ */
+#ifndef daylight
+#define daylight 0
+#endif
+
+/**
  * Structure used for saving date and time
  *
  * \ingroup DateTime
