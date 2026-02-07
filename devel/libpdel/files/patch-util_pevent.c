--- util/pevent.c.orig	2009-05-13 21:36:05 UTC
+++ util/pevent.c
@@ -147,6 +147,15 @@ struct pevent {
 		}							\
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
@@ -336,7 +345,11 @@ pevent_register(struct pevent_ctx *ctx, struct pevent 
 			ev->u.millis = 0;
 		pd_gettimeofday(&ev->when, NULL);
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
@@ -392,15 +405,16 @@ pevent_register(struct pevent_ctx *ctx, struct pevent 
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
 
@@ -565,6 +579,13 @@ loop:
 	if (ctx->notified) {
 		DBG(PEVENT, "ctx %p thread was notified", ctx);
 		(void)pd_read(ctx->pipe[0], &pevent_byte, 1);
+		ctx->notified = 0;
+	}
+
+	/* If we were intentionally woken up, read the wakeup byte */
+	if (ctx->notified) {
+		DBG(PEVENT, "ctx %p thread was notified", ctx);
+		(void)read(ctx->pipe[0], &pevent_byte, 1);
 		ctx->notified = 0;
 	}
 
