--- common/drivers/posix/timer_sigalarm.cpp.orig	Fri Sep 17 10:49:31 2004
+++ common/drivers/posix/timer_sigalarm.cpp	Fri Sep 17 10:50:25 2004
@@ -67,7 +67,7 @@
 
 	Timer_SigAlarm *dangit;
 
-	(void*)dangit=data;
+	dangit=(Timer_SigAlarm*)data;
 
 	dangit->callback();
 
