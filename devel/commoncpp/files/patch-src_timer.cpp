--- src/timer.cpp.orig	Tue Jan 23 21:09:13 2007
+++ src/timer.cpp	Tue Sep 11 13:12:41 2007
@@ -117,7 +117,7 @@
 	active = true;
 }
 
-#ifdef	HAVE_HIRES_TIMER
+#if defined(HAVE_HIRES_TIMER) && !defined(__FreeBSD__)
 void TimerPort::sleepTimer(void)
 {
 	struct timespec ts;
