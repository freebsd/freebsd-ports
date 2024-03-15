--- src/gtkam-gimp.c.orig	2024-03-15 06:53:10 UTC
+++ src/gtkam-gimp.c
@@ -258,7 +258,7 @@ static void
 }
 
 static void
-run_capture (gchar *name, gint nparams, GimpParam *param, gint *nreturn_vals,
+run_capture (const gchar *name, gint nparams, const GimpParam *param, gint *nreturn_vals,
 	     GimpParam **return_vals)
 {
 	GtkamCamera *camera = NULL;
@@ -387,7 +387,7 @@ static void
 }
 
 static void
-run_load (gchar *name, gint nparams, GimpParam *param, gint *nreturn_vals,
+run_load (const gchar *name, gint nparams, const GimpParam *param, gint *nreturn_vals,
 	  GimpParam **return_vals)
 {
 	GtkWidget *fsel;
@@ -457,7 +457,7 @@ static void
 }
 
 static void
-run (gchar *name, gint nparams, GimpParam *params, gint *nreturn_vals,
+run (const gchar *name, gint nparams, const GimpParam *params, gint *nreturn_vals,
      GimpParam **return_vals)
 {
 	static GimpParam values[1];
