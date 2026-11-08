--- src/event/workqueue.c.orig	2026-05-01 02:25:26 UTC
+++ src/event/workqueue.c
@@ -326,8 +326,10 @@ _dispatch_workq_count_runnable_workers(dispatch_workq_
 
 	for (int i = 0; i < mon->num_registered_tids; ++i) {
 		dispatch_tid tid = mon->registered_tids[i];
-		for (int j = 0; i < count; ++i) {
-			if ((dispatch_tid)kp[j].ki_tid != tid) { continue; }
+		for (int j = 0; j < count; ++j) {
+			if (((dispatch_tid)kp[j].ki_tid << 2) != tid) {
+				continue;
+			}
 			if (kp[j].ki_stat == SRUN || kp[j].ki_stat == SIDL) {
 				++runners;
 				break;
