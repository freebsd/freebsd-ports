--- apps/pdfapp.c.orig	2013-02-26 12:07:15.000000000 -0500
+++ apps/pdfapp.c	2013-05-06 11:13:27.210765076 -0400
@@ -1142,11 +1142,15 @@ void pdfapp_onkey(pdfapp_t *app, int c)
 		break;
 
 	case 'j':
+ 		if (app->pany + fz_pixmap_height(app->ctx, app->image) <= app->winh)
+ 			goto pagedown;
 		app->pany -= fz_pixmap_height(app->ctx, app->image) / 10;
 		pdfapp_showpage(app, 0, 0, 1, 0);
 		break;
 
 	case 'k':
+ 		if (app->pany >= 0)
+ 			goto pageup;
 		app->pany += fz_pixmap_height(app->ctx, app->image) / 10;
 		pdfapp_showpage(app, 0, 0, 1, 0);
 		break;
@@ -1214,6 +1218,7 @@ void pdfapp_onkey(pdfapp_t *app, int c)
 	 */
 
 	case ',':
+	pageup:
 		panto = PAN_TO_BOTTOM;
 		if (app->numberlen > 0)
 			app->pageno -= atoi(app->number);
@@ -1222,6 +1227,7 @@ void pdfapp_onkey(pdfapp_t *app, int c)
 		break;
 
 	case '.':
+	pagedown:
 		panto = PAN_TO_TOP;
 		if (app->numberlen > 0)
 			app->pageno += atoi(app->number);
@@ -1523,6 +1529,12 @@ void pdfapp_onmouse(pdfapp_t *app, int x
 				int isx = (modifiers & (1<<0));
 				int xstep = isx ? 20 * dir : 0;
 				int ystep = !isx ? 20 * dir : 0;
+				if (!isx && dir < 0 && app->pany +
+				    fz_pixmap_height(app->ctx, app->image) <= app->winh)
+					pdfapp_onkey(app, 'j');
+				else if (!isx && dir > 0 && app->pany >= 0)
+					pdfapp_onkey(app, 'k');
+				else
 				pdfapp_panview(app, app->panx + xstep, app->pany + ystep);
 			}
 		}
