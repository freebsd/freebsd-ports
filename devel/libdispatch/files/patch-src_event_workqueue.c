--- src/event/workqueue.c.orig	2021-09-17 04:54:52 UTC
+++ src/event/workqueue.c
@@ -180,6 +180,52 @@ _dispatch_workq_count_runnable_workers(dispatch_workq_
 
 	_dispatch_unfair_lock_unlock(&mon->registered_tid_lock);
 }
+#elif defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/proc.h>
+
+static void
+_dispatch_workq_count_runnable_workers(dispatch_workq_monitor_t mon)
+{
+	struct kinfo_proc kp[WORKQ_MAX_TRACKED_TIDS] = {0};
+	size_t size, len;
+	int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, (int)getpid(), (int)sizeof(struct kinfo_proc), 0};
+	if (sysctl(mib, 6, NULL, &size, NULL, 0) < 0) {
+		_dispatch_debug("workq: Failed to sysctl1");
+		return;
+	}
+
+	size = size > sizeof(kp)? sizeof(kp): size;
+	len = size / sizeof(struct kinfo_proc);
+	mib[5] = (int)len;
+	if (sysctl(mib, 6, kp, &size, NULL, 0) < 0) {
+		_dispatch_debug("workq: Failed to sysctl2");
+		return;
+	}
+
+	int running_count = 0;
+
+	_dispatch_unfair_lock_lock(&mon->registered_tid_lock);
+
+	for (int i = 0; i < mon->num_registered_tids; i++) {
+		dispatch_tid tid = mon->registered_tids[i];
+		for (size_t j = 0; j < len; j++) {
+			if ((dispatch_tid)kp[j].p_tid != tid) {
+				continue;
+			}
+
+			if (kp[j].p_stat == SRUN || kp[j].p_stat == SIDL || kp[j].p_stat == SONPROC) {
+				running_count++;
+				break;
+			}
+		}
+	}
+
+	mon->num_runnable = running_count;
+
+	_dispatch_unfair_lock_unlock(&mon->registered_tid_lock);
+}
 #else
 #error must define _dispatch_workq_count_runnable_workers
 #endif
