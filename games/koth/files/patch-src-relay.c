--- src/relay.c.orig	Mon Feb  3 01:34:54 2003
+++ src/relay.c	Sat Oct 16 20:29:42 2004
@@ -260,6 +260,7 @@
 		    else goto bail;
 		    goto nextpkt;
 		bail:
+		    ;
 		}
 	    }	
 	}
