--- tevent_poll.c.orig	2026-08-09 16:32:38 UTC
+++ tevent_poll.c
@@ -470,8 +470,13 @@ static int poll_event_loop_poll(struct tevent_context 
 	}
 
 	if (tvalp != NULL) {
-		timeout = tvalp->tv_sec * 1000;
-		timeout += (tvalp->tv_usec + 999) / 1000;
+		/* clamp: far-future timer overflows int ms -> poll(2) EINVAL busy-loop */
+		if (tvalp->tv_sec > (INT_MAX / 1000) - 1) {
+			timeout = INT_MAX;
+		} else {
+			timeout = tvalp->tv_sec * 1000;
+			timeout += (tvalp->tv_usec + 999) / 1000;
+		}
 	}
 
 	ok = poll_event_sync_arrays(ev, poll_ev);
