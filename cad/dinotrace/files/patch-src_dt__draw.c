
$FreeBSD$

--- src/dt_draw.c.orig	Sun Aug 22 22:14:43 2004
+++ src/dt_draw.c	Sun Aug 22 22:18:04 2004
@@ -542,7 +542,9 @@
 		case STATE_Z:		dr_mask |= DR_Z; break;
 		default:		dr_mask |= DR_LOW | DR_HIGH; break;
 		}
-		color_value = MAX(color_value, nptr->siglw.stbits.color);
+		if (color_value > nptr->siglw.stbits.color);
+		color_value = nptr->siglw.stbits.color;
+
 		xright = MAX(xright, TIME_TO_XPOS (CPTR_TIME(nnptr)));
 		nptr = nnptr;
 	    }
