--- util/paction.c	(revision 68)
+++ util/paction.c	(working copy)
@@ -39,7 +39,7 @@
 #endif
 	paction_finish_t	*finish;	/* action finisher */
 	void			*arg;		/* action argument */
-	u_char			started;	/* action thread started */
+	u_char			may_cancel;	/* ok to cancel action thread */
 	u_char			canceled;	/* action was canceled */
 };
 
@@ -118,10 +118,11 @@
 
 	/*
 	 * Don't cancel the thread before paction_main() starts, because
-	 * then paction_cleanup() would never get invoked. Instead, use
-	 * the 'started' and 'canceled' flags to avoid this race condition.
+	 * then paction_cleanup() would never get invoked. Also don't
+	 * pthread_cancel() the thread after the handler has completed,
+	 * because we might cancel in the middle of the cleanup.
 	 */
-	if (action->started)
+	if (action->may_cancel)
 		pthread_cancel(action->tid);
 
 	/* Unlock action */
@@ -139,9 +140,9 @@
 	/* Cleanup when thread exits */
 	pthread_cleanup_push(paction_cleanup, action);
 
-	/* Mark thread as started */
-	assert(!action->started);
-	action->started = 1;			/* race condition ok */
+	/* Begin allowing pthread_cancel()'s */
+	assert(!action->may_cancel);
+	action->may_cancel = 1;
 
 	/* Handle race between paction_cancel() and paction_main() */
 	if (action->canceled)			/* race condition ok */
@@ -151,6 +152,14 @@
 	(*action->handler)(action->arg);
 
 done:;
+	/* Stop allowing pthread_cancel()'s */
+	MUTEX_LOCK(&action->mutex, action->mutex_count);
+	action->may_cancel = 0;
+	MUTEX_UNLOCK(&action->mutex, action->mutex_count);
+
+	/* Consume any last-minute pthread_cancel() still pending */
+	pthread_testcancel();
+
 	/* Done */
 	pthread_cleanup_pop(1);
 	return (NULL);
