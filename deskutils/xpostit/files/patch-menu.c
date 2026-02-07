--- menu.c~	1992-12-11 14:04:14.000000000 +0100
+++ menu.c	2023-02-13 23:44:16.137102000 +0100
@@ -120,7 +120,7 @@
 					      smeBSBObjectClass, menuwidget,
 					      NULL, 0);
 
-		XtAddCallback(entry, XtNcallback, HandleMenuSelection, i);
+		XtAddCallback(entry, XtNcallback, HandleMenuSelection, (XtPointer)i);
 	}
 		
 	XawSimpleMenuAddGlobalActions(appcontext);
