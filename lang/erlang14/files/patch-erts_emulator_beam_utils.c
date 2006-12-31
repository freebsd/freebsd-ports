
$FreeBSD$

--- erts/emulator/beam/utils.c.orig
+++ erts/emulator/beam/utils.c
@@ -2999,15 +2999,16 @@
 static void
 ptimer_timeout(ErtsSmpPTimer *ptimer)
 {
-    if (!(ptimer->timer.flags & ERTS_PTMR_FLG_CANCELLED)) {
 	if (is_internal_pid(ptimer->timer.id)) {
 	    Process *p;
-	    p = erts_pid2proc(NULL,
-			      0,
-			      ptimer->timer.id,
-			      ERTS_PROC_LOCK_MAIN|ERTS_PROC_LOCK_STATUS);
+	    p = erts_pid2proc_opt(NULL,
+				  0,
+				  ptimer->timer.id,
+				  ERTS_PROC_LOCK_MAIN|ERTS_PROC_LOCK_STATUS,
+				  ERTS_P2P_FLG_ALLOW_OTHER_X);
 	    if (p) {
-		if (!(ptimer->timer.flags & ERTS_PTMR_FLG_CANCELLED)) {
+		if (!p->is_exiting
+		    && !(ptimer->timer.flags & ERTS_PTMR_FLG_CANCELLED)) {
 		    ASSERT(*ptimer->timer.timer_ref == ptimer);
 		    *ptimer->timer.timer_ref = NULL;
 		    (*ptimer->timer.timeout_func)(p);
@@ -3028,7 +3029,6 @@
 		erts_smp_io_unlock();
 	    }
 	}
-    }
     free_ptimer(ptimer);
 }
 
