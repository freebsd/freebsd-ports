--- src/sheet/wire-item.c.orig	Wed May 24 14:16:30 2006
+++ src/sheet/wire-item.c	Wed May 24 21:13:43 2006
@@ -363,8 +363,8 @@
 		case GDK_BUTTON_PRESS:
 			switch (event->button.button) {
 				case 1: {
-					g_signal_stop_emission_by_name (G_OBJECT (sheet), "event");
 					double x, y;
+					g_signal_stop_emission_by_name (G_OBJECT (sheet), "event");
 					x = event->button.x - start_pos.x;
 					y = event->button.y - start_pos.y;
 					if ((x > -RESIZER_SIZE) && (x < RESIZER_SIZE) &&
