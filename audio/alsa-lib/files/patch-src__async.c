$NetBSD: patch-bk,v 1.1 2008/12/25 13:18:00 hasso Exp $

--- src/async.c~
+++ src/async.c
@@ -51,6 +51,15 @@ static LIST_HEAD(snd_async_handlers);
 
 static void snd_async_handler(int signo ATTRIBUTE_UNUSED, siginfo_t *siginfo, void *context ATTRIBUTE_UNUSED)
 {
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+	/* XXX XXX XXX */
+	struct list_head *i;
+	list_for_each(i, &snd_async_handlers) {
+		snd_async_handler_t *h = list_entry(i, snd_async_handler_t, glist);
+		if (h->callback)
+			h->callback(h);
+	}
+#else
 	int fd;
 	struct list_head *i;
 	//assert(siginfo->si_code == SI_SIGIO);
@@ -60,6 +69,7 @@ static void snd_async_handler(int signo 
 		if (h->fd == fd && h->callback)
 			h->callback(h);
 	}
+#endif
 }
 
 /**
