--- src/loaders/pp10_load.c.orig	Sat Dec 30 03:08:46 2000
+++ src/loaders/pp10_load.c	Sat Sep 18 23:44:27 2004
@@ -226,6 +226,7 @@
 		    case 0x0a:
 			event->fxt = 0x00;
 		    case 0x0f:
+			;
 		    }
 		}
 
