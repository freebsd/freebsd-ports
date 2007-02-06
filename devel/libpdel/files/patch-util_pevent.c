--- util/pevent.c	2005/09/10 20:19:46	972
+++ util/pevent.c	2006/10/07 23:59:17	980
@@ -122,6 +122,15 @@
 		_pevent_unref(ev);					\
 	} while (0)
 
+#define PEVENT_SET_OCCURRED(ctx, ev)					\
+	do {								\
+		(ev)->flags |= PEVENT_OCCURRED;				\
+		if ((ev) != TAILQ_FIRST(&ctx->events)) {		\
+			TAILQ_REMOVE(&(ctx)->events, (ev), next);	\
+			TAILQ_INSERT_HEAD(&(ctx)->events, (ev), next);	\
+		}							\
+	} while (0)
+
 /* Internal functions */
 static void	pevent_ctx_service(struct pevent *ev);
 static void	*pevent_ctx_main(void *arg);
@@ -436,7 +445,7 @@
 		goto done;
 
 	/* Mark event as having occurred */
-	ev->flags |= PEVENT_OCCURRED;
+	PEVENT_SET_OCCURRED(ctx, ev);
 
 	/* Wake up thread if event is still in the queue */
 	if ((ev->flags & PEVENT_ENQUEUED) != 0)
@@ -490,6 +499,7 @@
 	struct timeval now;
 	struct pollfd *fd;
 	struct pevent *ev;
+	struct pevent *next_ev;
 	int poll_idx;
 	int timeout;
 	int r;
@@ -529,6 +539,13 @@
 		}
 	}
 
+	/* If we were intentionally woken up, read the wakeup byte */
+	if (ctx->notified) {
+		DBG(PEVENT, "ctx %p thread was notified", ctx);
+		(void)read(ctx->pipe[0], &pevent_byte, 1);
+		ctx->notified = 0;
+	}
+
 	/* Add event for the notify pipe */
 	poll_idx = 0;
 	if (ctx->fds_alloc > 0) {
@@ -587,7 +604,7 @@
 		switch (ev->type) {
 		case PEVENT_MESG_PORT:
 			if (mesg_port_qlen(ev->u.port) > 0)
-				ev->flags |= PEVENT_OCCURRED;
+				PEVENT_SET_OCCURRED(ctx, ev);
 			break;
 		default:
 			break;
@@ -621,7 +638,8 @@
 	gettimeofday(&now, NULL);
 
 	/* Mark poll() events that have occurred */
-	TAILQ_FOREACH(ev, &ctx->events, next) {
+	for (ev = TAILQ_FIRST((&ctx->events)); ev != NULL; ev = next_ev) {
+		next_ev = TAILQ_NEXT(ev, next);
 		assert(ev->magic == PEVENT_MAGIC);
 		switch (ev->type) {
 		case PEVENT_READ:
@@ -631,33 +649,23 @@
 			fd = &ctx->fds[ev->poll_idx];
 			if ((fd->revents & ((ev->type == PEVENT_READ) ?
 			    READABLE_EVENTS : WRITABLE_EVENTS)) != 0)
-				ev->flags |= PEVENT_OCCURRED;
+				PEVENT_SET_OCCURRED(ctx, ev);
 			break;
 		case PEVENT_TIME:
 			if (timercmp(&ev->when, &now, <=))
-				ev->flags |= PEVENT_OCCURRED;
+				PEVENT_SET_OCCURRED(ctx, ev);
 			break;
 		default:
 			break;
 		}
 	}
 
-	/* If we were intentionally woken up, read the wakeup byte */
-	if (ctx->notified) {
-		DBG(PEVENT, "ctx %p thread was notified", ctx);
-		(void)read(ctx->pipe[0], &pevent_byte, 1);
-		ctx->notified = 0;
-	}
-
 	/* Service all events that are marked as having occurred */
 	while (1) {
 
-		/* Find next event that needs service XXX this is O(n^2) XXX */
-		TAILQ_FOREACH(ev, &ctx->events, next) {
-			if ((ev->flags & PEVENT_OCCURRED) != 0)
-				break;
-		}
-		if (ev == NULL)
+		/* Find next event that needs service */
+		ev = TAILQ_FIRST(&ctx->events);
+		if (ev == NULL || (ev->flags & PEVENT_OCCURRED) == 0)
 			break;
 		DBG(PEVENT, "ctx %p thread servicing ev %p", ctx, ev);
 
