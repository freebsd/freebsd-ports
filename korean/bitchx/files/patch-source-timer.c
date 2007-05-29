--- source/timer.c.orig	Mon Dec 18 22:29:15 2006
+++ source/timer.c	Mon Dec 18 22:29:30 2006
@@ -148,7 +148,7 @@
  * This is put here on purpose -- we dont want any of the above functions
  * to have any knowledge of this struct.
  */
-static TimerList *PendingTimers;
+TimerList *PendingTimers;
 static char *schedule_timer (TimerList *ntimer);
 
 static char *current_exec_timer = empty_string;
