Index: edisplay.cc
===================================================================
--- edisplay/edisplay.cc	(revision 1751)
+++ edisplay/edisplay.cc	(revision 1752)
@@ -269,12 +269,14 @@
       
       /* the following is specific to the engine */
       einfo->info.display = dpy;
-      einfo->info.visual =
-	einfo->func.best_visual_get (dpy, DefaultScreen(dpy));
-      einfo->info.colormap =
-	einfo->func.best_colormap_get(dpy,DefaultScreen(dpy));
-
+#ifdef WITHEVAS_X11_SCREEN
+      einfo->info.screen = DefaultScreen(dpy);
+      einfo->info.visual = einfo->func.best_visual_get(einfo);
+      einfo->info.colormap = einfo->func.best_colormap_get(einfo);
+#else
+      einfo->info.visual = einfo->func.best_visual_get(dpy, DefaultScreen(dpy));
       einfo->info.colormap = einfo->func.best_colormap_get(dpy, DefaultScreen(dpy));
+#endif
       einfo->info.drawable = win;
       einfo->info.depth = depth;
       
