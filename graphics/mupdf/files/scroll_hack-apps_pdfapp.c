--- apps/pdfapp.c.orig	2012-03-29 05:46:53.000000000 -0500
+++ apps/pdfapp.c	2012-04-07 16:43:55.030462608 -0500
@@ -774,11 +774,15 @@ void pdfapp_onkey(pdfapp_t *app, int c)
 		break;
 
 	case 'j':
+ 		if (app->pany + fz_pixmap_height(app->ctx, app->image) <= app->winh)
+ 			goto pagedown;
 		app->pany -= fz_pixmap_height(app->ctx, app->image) / 10;
 		pdfapp_showpage(app, 0, 0, 1);
 		break;
 
 	case 'k':
+ 		if (app->pany >= 0)
+ 			goto pageup;
 		app->pany += fz_pixmap_height(app->ctx, app->image) / 10;
 		pdfapp_showpage(app, 0, 0, 1);
 		break;
@@ -842,6 +846,7 @@ void pdfapp_onkey(pdfapp_t *app, int c)
 	 */
 
 	case ',':
+	pageup:
 		panto = PAN_TO_BOTTOM;
 		if (app->numberlen > 0)
 			app->pageno -= atoi(app->number);
@@ -850,6 +855,7 @@ void pdfapp_onkey(pdfapp_t *app, int c)
 		break;
 
 	case '.':
+	pagedown:
 		panto = PAN_TO_TOP;
 		if (app->numberlen > 0)
 			app->pageno += atoi(app->number);
@@ -1039,6 +1045,12 @@ void pdfapp_onmouse(pdfapp_t *app, int x
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
