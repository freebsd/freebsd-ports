--- lib-src/portaudio/pa_unix_oss/pa_unix.c.orig	Tue Nov 30 21:18:35 2004
+++ lib-src/portaudio/pa_unix_oss/pa_unix.c	Tue Nov 30 21:33:58 2004
@@ -422,7 +422,7 @@
     maxPri = sched_get_priority_max(SCHEDULER_POLICY);
     if( schp.sched_priority > maxPri ) schp.sched_priority = maxPri;
 
-    if (sched_setscheduler(0, SCHEDULER_POLICY, &schp) != 0)
+    if (pthread_setschedparam(pahsc->pahsc_WatchDogThread, SCHEDULER_POLICY, &schp) != 0)
     {
         ERR_RPT(("PaHost_WatchDogProc: cannot set watch dog priority!\n"));
         goto killAudio;
@@ -465,7 +465,7 @@
 lowerAudio:
     {
         struct sched_param    schat = { 0 };
-        if( sched_setscheduler(pahsc->pahsc_AudioThreadPID, SCHED_OTHER, &schat) != 0)
+        if( pthread_setschedparam(pahsc->pahsc_AudioThread, SCHED_OTHER, &schat) != 0)
         {
             ERR_RPT(("PaHost_WatchDogProc: failed to lower audio priority. errno = %d\n", errno ));
             /* Fall through into killing audio thread. */
@@ -585,7 +585,7 @@
                                   sched_get_priority_min(SCHEDULER_POLICY)) / 2;
     schp.sched_priority = pahsc->pahsc_AudioPriority;
 
-    if (sched_setscheduler(0, SCHEDULER_POLICY, &schp) != 0)
+    if (pthread_setschedparam(pahsc->pahsc_AudioThread, SCHEDULER_POLICY, &schp) != 0)
     {
         DBUG(("PortAudio: only superuser can use real-time priority.\n"));
     }
