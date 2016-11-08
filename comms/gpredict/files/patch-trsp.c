--- src/trsp-conf.c.orig	2016-06-04 02:02:30.359797000 -0500
+++ src/trsp-conf.c	2016-06-04 02:02:47.233560000 -0500
@@ -186,9 +186,9 @@
     for (i = 0; i < n; i++) {
         trsp = (trsp_t *) g_slist_nth_data (trsplist, i);
         g_free (trsp->name);
-        g_free (trsp);
         if (trsp->mode)
             g_free (trsp->mode);
+        g_free (trsp);
     }
     g_slist_free (trsplist);
     trsplist = NULL;
