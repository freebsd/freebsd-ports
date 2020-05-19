--- ./platform/x11/pdfapp.c.orig	2020-05-05 04:29:09.000000000 -0700
+++ ./platform/x11/pdfapp.c	2020-05-17 08:47:00.137902000 -0700
@@ -1462,6 +1462,8 @@
 
 	case 'j':
 		{
+      if (app->pany + app->imgh <= app->winh)
+        goto pagedown;
 			if (app->imgh <= app->winh || app->pany <= app->winh - app->imgh)
 			{
 				panto = PAN_TO_TOP;
@@ -1477,6 +1479,8 @@
 
 	case 'k':
 		{
+      if (app->pany >= 0)
+        goto pageup;
 			if (app->imgh <= app->winh || app->pany == 0)
 			{
 				panto = PAN_TO_BOTTOM;
@@ -1550,6 +1554,7 @@
 	 */
 
 	case ',':
+    pageup:
 		panto = DONT_PAN;
 		if (app->numberlen > 0)
 			app->pageno -= atoi(app->number);
@@ -1558,6 +1563,7 @@
 		break;
 
 	case '.':
+    pagedown:
 		panto = DONT_PAN;
 		if (app->numberlen > 0)
 			app->pageno += atoi(app->number);
