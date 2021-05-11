$NetBSD: patch-bk,v 1.1 2008/12/25 13:18:00 hasso Exp $

--- src/async.c.orig	2020-02-19 09:35:39 UTC
+++ src/async.c
@@ -54,6 +54,15 @@ static LIST_HEAD(snd_async_handlers);
 
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
@@ -66,6 +75,7 @@ static void snd_async_handler(int signo ATTRIBUTE_UNUS
 		if (h->fd == fd && h->callback)
 			h->callback(h);
 	}
+#endif
 }
 
 /**
