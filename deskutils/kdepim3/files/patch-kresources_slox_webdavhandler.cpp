===================================================================
RCS file: /usr/repos/kde/kdepim/kresources/slox/webdavhandler.cpp,v
retrieving revision 1.8.2.1
retrieving revision 1.8.2.2
diff -u -p -r1.8.2.1 -r1.8.2.2
--- kresources/slox/webdavhandler.cpp	2004/09/28 14:25:44	1.8.2.1
+++ kresources/slox/webdavhandler.cpp	2004/10/07 23:35:53	1.8.2.2
@@ -20,7 +20,13 @@
 
 #include "webdavhandler.h"
 
+#ifdef HAVE_VALUES_H
 #include <values.h>
+#else
+#ifdef HAVE_SYS_LIMITS_H
+#include <sys/limits.h>
+#endif
+#endif
 
 #include <libkdepim/kpimprefs.h>
 
@@ -150,9 +156,9 @@ QDateTime WebdavHandler::sloxToQDateTime
 
   if (preEpoch) {
     dt.setTime_t( 0, Qt::UTC );
-    if (ticks > MAXINT) {
-      dt = dt.addSecs(-MAXINT);
-      ticks -= MAXINT;
+    if (ticks > INT_MAX) {
+      dt = dt.addSecs(-INT_MAX);
+      ticks -= INT_MAX;
     }
     dt = dt.addSecs(-((long) ticks));
   }
