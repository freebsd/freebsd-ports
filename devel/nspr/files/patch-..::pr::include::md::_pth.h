
$FreeBSD$

--- ../pr/include/md/_pth.h.orig	Wed Jun 21 00:23:43 2000
+++ ../pr/include/md/_pth.h	Tue Dec 18 11:24:06 2001
@@ -199,7 +199,7 @@
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
 #endif /* defined(_PR_DCETHREADS) */
 
-#elif defined(LINUX)
+#elif defined(LINUX) || defined(FREEBSD)
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
 #elif defined(NTO)
@@ -219,7 +219,7 @@
  */
 #define PT_PRIO_MIN            1
 #define PT_PRIO_MAX            127
-#elif defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
+#elif defined(NETBSD) || defined(OPENBSD) \
 	|| defined(BSDI) || defined(RHAPSODY) /* XXX */
 #define PT_PRIO_MIN            0
 #define PT_PRIO_MAX            126
