--- playdv/display.c.orig	Wed Nov 21 03:47:29 2001
+++ playdv/display.c	Wed Nov 21 03:51:04 2001
@@ -47,6 +47,8 @@
 #include <popt.h>
 #endif
 
+dv_display_t 	*dv_dpy_on_exit_hack = NULL;
+
 static int      dv_display_SDL_init(dv_display_t *dv_dpy, gchar *w_name, gchar   *i_name           );
 static gboolean dv_display_gdk_init(dv_display_t *dv_dpy, gint  *argc,   gchar ***argv             );
 
@@ -257,6 +259,7 @@
   } /* switch */
 
   free(dv_dpy);
+  dv_dpy_on_exit_hack = NULL;
 } /* dv_display_exit */
 
 static gboolean
@@ -675,6 +678,13 @@
   } /* if */
 } /* dv_display_exit_handler */
 
+static void
+dv_display_on_exit_hack_handler()
+{
+  if(dv_dpy_on_exit_hack != NULL) {
+    dv_display_exit(dv_dpy_on_exit_hack);
+  } /* if */
+} /* dv_display_exit_handler */
 
 gboolean
 dv_display_init(dv_display_t *dv_dpy, gint *argc, gchar ***argv, gint width, gint height, 
@@ -804,7 +814,8 @@
   fprintf(stderr, " Using gtk for display\n");
 
  ok:
-  on_exit(dv_display_exit_handler, dv_dpy);
+  dv_dpy_on_exit_hack = dv_dpy;
+  atexit(dv_display_on_exit_hack_handler);
   return(TRUE);
 
  fail:
