Include necessary header <time.h>

--- plan/plugins/schedulers/tj/PlanTJScheduler.h.orig	2017-01-04 17:01:13 UTC
+++ plan/plugins/schedulers/tj/PlanTJScheduler.h
@@ -32,6 +32,8 @@
 #include <QMap>
 #include <QList>
 
+#include <time.h>
+
 class QDateTime;
 
 namespace TJ
