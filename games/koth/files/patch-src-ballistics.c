--- src/ballistics.c.orig	Wed Jan 15 05:12:43 2003
+++ src/ballistics.c	Sat Oct 16 20:33:24 2004
@@ -92,6 +92,7 @@
 	    break;
 	case WALL_LAST:
 	    /* just to satisfy gcc -Wall */
+	    ;
     }
 }
 
@@ -210,7 +211,7 @@
 		break;
 	    case WALL_RANDOM:	/* both of this can't happen, */
 	    case WALL_LAST:	/* so they are here to satisfy gcc -Wall */
-
+		;
 	}
     }
     return FLYING;
