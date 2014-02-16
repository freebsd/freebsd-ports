From 0513c855cba69b96e4c9d2200719249a8a0c586e Mon Sep 17 00:00:00 2001
From: Dan Winship <danw@gnome.org>
Date: Wed, 10 Apr 2013 11:39:12 -0400
Subject: [PATCH] gmain: fix double-unlock in g_main_context_unref()

When unreffing a context with sources still attached, it would end up
unlocking an already-unlocked context, causing crashes on platforms
that (unlike Linux) actually check for that.

https://bugzilla.gnome.org/show_bug.cgi?id=697595
---
 glib/gmain.c | 6 +++++-
 1 file changed, 5 insertions(+), 1 deletion(-)

diff --git a/glib/gmain.c b/glib/gmain.c
index 68a7f8e..d6037ba 100644
--- glib/gmain.c
+++ glib/gmain.c
@@ -520,12 +520,16 @@ g_main_context_unref (GMainContext *context)
   main_context_list = g_slist_remove (main_context_list, context);
   G_UNLOCK (main_context_list);
 
+  /* g_source_iter_next() assumes the context is locked. */
+  LOCK_CONTEXT (context);
   g_source_iter_init (&iter, context, TRUE);
   while (g_source_iter_next (&iter, &source))
     {
       source->context = NULL;
-      g_source_destroy_internal (source, context, FALSE);
+      g_source_destroy_internal (source, context, TRUE);
     }
+  UNLOCK_CONTEXT (context);
+
   for (sl_iter = context->source_lists; sl_iter; sl_iter = sl_iter->next)
     {
       list = sl_iter->data;
-- 
1.8.1.4
