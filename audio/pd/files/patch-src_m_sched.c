--- src/m_sched.c.orig	2011-03-10 15:02:41.000000000 +0900
+++ src/m_sched.c	2011-04-06 19:40:16.000000000 +0900
@@ -394,8 +394,10 @@
 the audio I/O system is still busy with previous transfers.
 */
 
+#if !defined(__FreeBSD__)
 void sys_pollmidiqueue( void);
 void sys_initmidiqueue( void);
+#endif
 
  /* sys_idlehook is a hook the user can fill in to grab idle time.  Return
 nonzero if you actually used the time; otherwise we're really really idle and
@@ -419,7 +421,9 @@
         sys_sleepgrain = 100;
     else if (sys_sleepgrain > 5000)
         sys_sleepgrain = 5000;
+#if !defined(__FreeBSD__)
     sys_initmidiqueue();
+#endif
     while (!sys_quit)
     {
         int didsomething = 0;
@@ -476,7 +480,9 @@
                     timeforward = SENDDACS_YES;
             else timeforward = SENDDACS_NO;
         }
+#if !defined(__FreeBSD__)
         sys_setmiditimediff(0, 1e-6 * sys_schedadvance);
+#endif
         sys_addhist(1);
         if (timeforward != SENDDACS_NO)
             sched_tick(sys_time + sys_time_per_dsp_tick);
@@ -484,7 +490,9 @@
             didsomething = 1;
 
         sys_addhist(2);
+#if !defined(__FreeBSD__)
         sys_pollmidiqueue();
+#endif
         if (sys_pollgui())
         {
             if (!didsomething)
@@ -523,11 +531,15 @@
 void sched_audio_callbackfn(void)
 {
     sys_lock();
+#if !defined(__FreeBSD__)
     sys_setmiditimediff(0, 1e-6 * sys_schedadvance);
+#endif
     sys_addhist(1);
     sched_tick(sys_time + sys_time_per_dsp_tick);
     sys_addhist(2);
+#if !defined(__FreeBSD__)
     sys_pollmidiqueue();
+#endif
     sys_addhist(3);
     sys_pollgui();
     sys_addhist(5);
@@ -538,7 +550,9 @@
 
 static void m_callbackscheduler(void)
 {
+#if !defined(__FreeBSD__)
     sys_initmidiqueue();
+#endif
     while (!sys_quit)
     {
         double timewas = sys_time;
