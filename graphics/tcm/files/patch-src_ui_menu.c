--- src/ui/menu.c.bak	2007-08-12 19:22:03.000000000 +0200
+++ src/ui/menu.c	2007-08-12 19:22:15.000000000 +0200
@@ -217,7 +217,7 @@
 					XmNindicatorType, XmONE_OF_MANY, (void *)0);
 			}
 			// selected or not ?
-			if ((int)items[i].userData & 0x1)
+			if ((intptr_t)items[i].userData & 0x1)
 				XtVaSetValues(submenu, XmNset, True, (void *)0);
 
 		}
