--- parpar/gf16/threadqueue.h.orig	2023-03-22 08:33:16 UTC
+++ parpar/gf16/threadqueue.h
@@ -252,7 +252,7 @@ class MessageThread {
 		pthread_t self = pthread_self();
 		if(!pthread_getschedparam(self, &policy, &param)) {
 			if(policy == SCHED_OTHER) {
-				#ifdef __MACH__
+				#if defined(__MACH__) || defined(__FreeBSD__)
 				// MacOS doesn't support SCHED_BATCH, but does seem to permit priorities on SCHED_OTHER
 				int min = sched_get_priority_min(policy);
 				if(min < param.sched_priority) {
