--- event.c.orig	2011-02-22 09:41:20.016483538 +0100
+++ event.c	2011-02-22 09:41:56.252380281 +0100
@@ -279,9 +279,14 @@
 	int res = 0;
 	struct event *ev;
 
+#if 0
+	/* Right now, reinit always takes effect, since even if the
+	   backend doesn't require it, the signal socketpair code does.
+	 */
 	/* check if this event mechanism requires reinit */
 	if (!evsel->need_reinit)
 		return (0);
+#endif
 
 	/* prevent internal delete */
 	if (base->sig.ev_signal_added) {
@@ -294,7 +299,7 @@
 			    EVLIST_ACTIVE);
 		base->sig.ev_signal_added = 0;
 	}
-	
+
 	if (base->evsel->dealloc != NULL)
 		base->evsel->dealloc(base, base->evbase);
 	evbase = base->evbase = evsel->init(base);
