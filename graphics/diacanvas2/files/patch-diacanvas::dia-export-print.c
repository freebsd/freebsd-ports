--- diacanvas/dia-export-print.c.orig	Sat Aug 28 00:01:51 2004
+++ diacanvas/dia-export-print.c	Sat Aug 28 00:07:51 2004
@@ -310,10 +310,10 @@
 			print_image ((DiaShapeImage *)shape, context);
 			break;
 		case DIA_SHAPE_WIDGET:
-			g_message (__FUNCTION__": Widget not yet implemented.");
+			g_message ("%s: Widget not yet implemented.", __func__);
 			break;
 		case DIA_SHAPE_CLIP:
-			g_message (__FUNCTION__": Clip not yet implemented.");
+			g_message ("%s: Clip not yet implemented.", __func__);
 			break;
 		default:
 			g_message ("Shape with type %d is not (yet) implemented", shape->type);
