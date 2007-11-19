--- util/pevent.c.orig	2005-01-21 23:02:19.000000000 +0200
+++ util/pevent.c	2007-11-11 16:06:04.000000000 +0200
@@ -155,6 +155,15 @@
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
@@ -338,7 +347,11 @@
 			ev->u.millis = 0;
 		gettimeofday(&ev->when, NULL);
 		ev->when.tv_sec += ev->u.millis / 1000;
-		ev->when.tv_usec += ev->u.millis % 1000;
+		ev->when.tv_usec += (ev->u.millis % 1000) * 1000;
+		if (ev->when.tv_usec > 1000000) {
+			ev->when.tv_sec++;
+			ev->when.tv_usec -= 1000000;
+		}
 		break;
 	case PEVENT_MESG_PORT:
 		va_start(args, type);
@@ -394,15 +407,16 @@
 	} else
 		pevent_ctx_notify(ctx);
 
+	/* Caller gets the one reference */
+	ev->peventp = peventp;
+	*peventp = ev;
+
 	/* Add event to the pending event list */
 	PEVENT_ENQUEUE(ctx, ev);
 
 	/* Unlock context */
 	MUTEX_UNLOCK(&ctx->mutex, ctx->mutex_count);
 
-	/* Done; caller gets the one reference */
-	ev->peventp = peventp;
-	*peventp = ev;
 	return (0);
 }
 
@@ -469,7 +483,7 @@
 		goto done;
 
 	/* Mark event as having occurred */
-	ev->flags |= PEVENT_OCCURRED;
+	PEVENT_SET_OCCURRED(ctx, ev);
 
 	/* Wake up thread if event is still in the queue */
 	if ((ev->flags & PEVENT_ENQUEUED) != 0)
@@ -523,6 +537,7 @@
 	struct timeval now;
 	struct pollfd *fd;
 	struct pevent *ev;
+	struct pevent *next_ev;
 	int poll_idx;
 	int timeout;
 	int r;
@@ -562,6 +577,13 @@
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
@@ -620,7 +642,7 @@
 		switch (ev->type) {
 		case PEVENT_MESG_PORT:
 			if (mesg_port_qlen(ev->u.port) > 0)
-				ev->flags |= PEVENT_OCCURRED;
+				PEVENT_SET_OCCURRED(ctx, ev);
 			break;
 		default:
 			break;
@@ -654,7 +676,8 @@
 	gettimeofday(&now, NULL);
 
 	/* Mark poll() events that have occurred */
-	TAILQ_FOREACH(ev, &ctx->events, next) {
+	for (ev = TAILQ_FIRST((&ctx->events)); ev != NULL; ev = next_ev) {
+		next_ev = TAILQ_NEXT(ev, next);
 		assert(ev->magic == PEVENT_MAGIC);
 		switch (ev->type) {
 		case PEVENT_READ:
@@ -664,33 +687,23 @@
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
 
