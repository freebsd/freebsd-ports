--- bforce/prot_zmsend.c.old	Thu Jul 29 23:35:04 2004
+++ bforce/prot_zmsend.c	Thu Jul 29 23:36:26 2004
@@ -414,7 +414,7 @@
 				case ZTX_CRCQACK:   txstate = ZTX_STARTDATA; break;
 				case ZTX_EOFACK:    txstate = ZTX_EOF;       break;
 				case ZTX_FINACK:    txstate = ZTX_FIN;       break;
-				default:
+				default:            break;
 				}
 				break;
 				
@@ -634,7 +634,7 @@
 				case ZTX_FINFOACK:  txstate = ZTX_FINFO;  break;
 				case ZTX_EOFACK:    txstate = ZTX_EOF;    break;
 				case ZTX_FINACK:    txstate = ZTX_FIN;    break;
-				default:
+				default:            break;
 				}
 				break;
 				
