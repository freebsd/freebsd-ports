--- apps/pdfapp.c.orig	2011-04-29 14:06:09.000000000 -0500
+++ apps/pdfapp.c	2011-05-16 19:58:55.650380651 -0500
@@ -777,11 +777,15 @@ void pdfapp_onkey(pdfapp_t *app, int c)
 		break;
 
 	case 'j':
+		if (app->pany + app->image->h <= app->winh)
+			goto pagedown;
 		app->pany -= app->image->h / 10;
 		pdfapp_showpage(app, 0, 0, 1);
 		break;
 
 	case 'k':
+		if (app->pany >= 0)
+			goto pageup;
 		app->pany += app->image->h / 10;
 		pdfapp_showpage(app, 0, 0, 1);
 		break;
@@ -843,6 +847,7 @@ void pdfapp_onkey(pdfapp_t *app, int c)
 	 */
 
 	case ',':
+	pageup:
 		panto = PAN_TO_BOTTOM;
 		if (app->numberlen > 0)
 			app->pageno -= atoi(app->number);
@@ -851,6 +856,7 @@ void pdfapp_onkey(pdfapp_t *app, int c)
 		break;
 
 	case '.':
+	pagedown:
 		panto = PAN_TO_TOP;
 		if (app->numberlen > 0)
 			app->pageno += atoi(app->number);
@@ -1022,6 +1028,11 @@ void pdfapp_onmouse(pdfapp_t *app, int x
 				int isx = (modifiers & (1<<0));
 				int xstep = isx ? 20 * dir : 0;
 				int ystep = !isx ? 20 * dir : 0;
+				if (!isx && dir < 0 && app->pany + app->image->h <= app->winh)
+					pdfapp_onkey(app, 'j');
+				else if (!isx && dir > 0 && app->pany >= 0)
+					pdfapp_onkey(app, 'k');
+				else
 				pdfapp_panview(app, app->panx + xstep, app->pany + ystep);
 			}
 		}
