--- pthread_src/PThreadConditionPrivateData.h.orig	Sun Jan 23 14:06:58 2005
+++ pthread_src/PThreadConditionPrivateData.h	Sun Jan 23 14:07:12 2005
@@ -24,9 +24,10 @@
 #ifndef _PTHREADCONDITIONPRIVATEDATA_H_
 #define _PTHREADCONDITIONPRIVATEDATA_H_
 
+#include <pthread.h>
+
 namespace OpenThreads {
 
-#include <pthread.h>
 #include <OpenThreads/Condition>
 
 class PThreadConditionPrivateData {
