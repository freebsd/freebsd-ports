--- bforce/prot_zmrecv.c.old	Thu Jul 29 23:29:04 2004
+++ bforce/prot_zmrecv.c	Thu Jul 29 23:32:23 2004
@@ -243,7 +243,8 @@
 			}
 			break;
 			
-		default: /* Ignore */
+		default:
+			break;
 		} /* end of switch(rxstate) */
 		
 		
@@ -266,7 +267,7 @@
 				switch(rxstate) {
 				case ZRX_INITACK: rxstate = ZRX_INIT;     break;
 				case ZRX_RPOSACK: rxstate = ZRX_SENDRPOS; break;
-				default:
+				default:	break;
 				}
 				break;
 				
@@ -356,7 +357,7 @@
 				switch(rxstate) {
 				case ZRX_INITACK: rxstate = ZRX_INIT;      break;
 				case ZRX_RPOSACK: rxstate = ZRX_SENDRPOS;  break;
-				default:
+				default:          break;
 				}
 				break;
 				
