
$FreeBSD$

--- src/gui/util/glame_param.c	2002/07/15 15:51:58	1.1
+++ src/gui/util/glame_param.c	2002/07/15 15:52:30
@@ -321,7 +321,7 @@
 		gparam->label = gtk_label_new(label);
 		gparam->u.adj = GTK_ADJUSTMENT(gtk_adjustment_new(
 			filterparam_val_int(param),
-			-MAXINT, MAXINT, 1.0, 10.0, 0.0));
+			-INT_MAX, INT_MAX, 1.0, 10.0, 0.0));
 		gparam->widget = gtk_spin_button_new(gparam->u.adj, 1, 0);
 		gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(gparam->widget),
 					    TRUE);
