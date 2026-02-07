--- uip/replsbr.c.orig	2001-04-04 16:05:17 UTC
+++ uip/replsbr.c
@@ -195,11 +195,12 @@ replout (inb, msg, drft, mp)
 			}
 		    } while (cptr = cptr->c_next);
 
-		while (state == FLDPLUS)
+		while (state == FLDPLUS) {
 		    state = m_getfld (state, name, tmpbuf, SBUFSIZ, inb);
 #ifdef JAPAN
 	            (void) ml_conv(tmpbuf);
 #endif /* JAPAN */
+		}
 		break;
 
 	    case LENERR: 
