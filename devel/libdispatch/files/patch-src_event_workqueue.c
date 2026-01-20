--- src/event/workqueue.c.orig	2025-03-07 00:50:44 UTC
+++ src/event/workqueue.c
@@ -247,6 +247,53 @@ _dispatch_workq_count_runnable_workers(dispatch_workq_
 
 	_dispatch_unfair_lock_unlock(&mon->registered_tid_lock);
 }
+#elif defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/proc.h>
+#include <sys/user.h>
+
+static void
+_dispatch_workq_count_runnable_workers(dispatch_workq_monitor_t mon)
+{
+    struct kinfo_proc kp[WORKQ_MAX_TRACKED_TIDS];
+    size_t size;
+    int count, runners = 0;
+    int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PID | KERN_PROC_INC_THREAD, (int)getpid()};
+
+    // get size we need
+    if (sysctl(mib, 4, NULL, &size, NULL, 0) < 0) {
+	_dispatch_debug("workq: failed to get size for kinfo_proc[] from sysctll");
+	return;
+    }
+
+    // only care about up to WORKQ_MAX_TRACKED_TIDS threads
+    size = MIN(sizeof(kp), size);
+
+    if (sysctl(mib, 4, kp, &size, NULL, 0) < 0) {
+	_dispatch_debug("workq: failed to get kinfo_proc[] from sysctl");
+	return;
+    }
+
+    count = (int)(size / sizeof(struct kinfo_proc));
+
+    _dispatch_unfair_lock_lock(&mon->registered_tid_lock);
+
+    for (int i = 0; i < mon->num_registered_tids; ++i) {
+	dispatch_tid tid = mon->registered_tids[i];
+	for (int j = 0; i < count; ++i) {
+	    if ((dispatch_tid)kp[j].ki_tid != tid) { continue; }
+	    if (kp[j].ki_stat == SRUN || kp[j].ki_stat == SIDL) {
+		++runners;
+		break;
+	    }
+	}
+    }
+
+    mon->num_runnable = runners;
+
+    _dispatch_unfair_lock_unlock(&mon->registered_tid_lock);
+}
 #else
 #error must define _dispatch_workq_count_runnable_workers
 #endif
