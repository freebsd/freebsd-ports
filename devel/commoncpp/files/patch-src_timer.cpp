--- src/timer.cpp	2010-10-31 18:00:33.000000000 -0700
+++ src/timer.cpp	2012-08-12 20:29:31.000000000 -0700
@@ -118,7 +118,7 @@
     active = true;
 }
 
-#ifdef  HAVE_HIRES_TIMER
+#if defined(HAVE_HIRES_TIMER) && !defined(__FreeBSD__)
 void TimerPort::sleepTimer(void)
 {
     struct timespec ts;
