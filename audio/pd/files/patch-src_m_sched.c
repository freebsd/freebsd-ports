$FreeBSD$

--- src/m_sched.c.orig	Wed Aug 27 18:02:19 2003
+++ src/m_sched.c	Tue Nov 11 22:45:18 2003
@@ -377,8 +377,8 @@ call.  This call returns true if samples
 the audio I/O system is still busy with previous transfers.
 */
 
-void sys_pollmidiqueue( void);
-void sys_initmidiqueue( void);
+//void sys_pollmidiqueue( void);
+//void sys_initmidiqueue( void);
 
 int m_scheduler( void)
 {
@@ -398,7 +398,7 @@ int m_scheduler( void)
     	sys_sleepgrain = 100;
     else if (sys_sleepgrain > 5000)
     	sys_sleepgrain = 5000;
-    sys_initmidiqueue();
+//    sys_initmidiqueue();
     while (1)
     {
     	int didsomething = 0;
@@ -440,7 +440,7 @@ int m_scheduler( void)
             	    timeforward = SENDDACS_YES;
     	    else timeforward = SENDDACS_NO;
     	}
-    	sys_setmiditimediff(0, 1e-6 * sys_schedadvance);
+//    	sys_setmiditimediff(0, 1e-6 * sys_schedadvance);
     	sys_addhist(1);
     	if (timeforward != SENDDACS_NO)
 	    sched_tick(sys_time + sys_time_per_dsp_tick);
@@ -448,7 +448,7 @@ int m_scheduler( void)
 	    didsomething = 1;
 
     	sys_addhist(2);
-    	sys_pollmidiqueue();
+//    	sys_pollmidiqueue();
     	if (sys_pollgui())
 	{
 	    if (!didsomething)
