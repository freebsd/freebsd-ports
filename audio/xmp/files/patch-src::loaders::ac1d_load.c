--- src/loaders/ac1d_load.c.orig	Sat Dec 30 03:08:12 2000
+++ src/loaders/ac1d_load.c	Sat Sep 18 23:41:47 2004
@@ -150,6 +150,7 @@
 		    case 0x0a:
 			event->fxt = 0x00;
 		    case 0x0f:
+			;
 		    }
 		}
 	    }
