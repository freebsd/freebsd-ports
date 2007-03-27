$FreeBSD$

--- src/m_sched.c.orig	Wed May 18 04:49:44 2005
+++ src/m_sched.c	Sun Mar 25 00:50:04 2007
@@ -377,8 +377,8 @@
 the audio I/O system is still busy with previous transfers.
 */
 
-void sys_pollmidiqueue( void);
-void sys_initmidiqueue( void);
+//void sys_pollmidiqueue( void);
+//void sys_initmidiqueue( void);
 
  /* sys_idlehook is a hook the user can fill in to grab idle time.  Return
 nonzero if you actually used the time; otherwise we're really really idle and
@@ -402,7 +402,7 @@
         sys_sleepgrain = 100;
     else if (sys_sleepgrain > 5000)
         sys_sleepgrain = 5000;
-    sys_initmidiqueue();
+//    sys_initmidiqueue();
     while (!sys_quit)
     {
         int didsomething = 0;
@@ -454,7 +454,7 @@
                     timeforward = SENDDACS_YES;
             else timeforward = SENDDACS_NO;
         }
-        sys_setmiditimediff(0, 1e-6 * sys_schedadvance);
+//        sys_setmiditimediff(0, 1e-6 * sys_schedadvance);
         sys_addhist(1);
         if (timeforward != SENDDACS_NO)
             sched_tick(sys_time + sys_time_per_dsp_tick);
@@ -462,7 +462,7 @@
             didsomething = 1;
 
         sys_addhist(2);
-        sys_pollmidiqueue();
+//        sys_pollmidiqueue();
         if (sys_pollgui())
         {
             if (!didsomething)
