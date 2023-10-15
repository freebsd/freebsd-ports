--- src/wx-thread.c.orig	2020-12-01 19:49:05 UTC
+++ src/wx-thread.c
@@ -171,7 +171,7 @@ int thread_wait_event(event_t *handle, int timeout)
 	event_pthread_t *event = (event_pthread_t *)handle;
 	struct timespec abstime;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	clock_gettime(CLOCK_REALTIME, &abstime);
 #else
         struct timeval now;
