--- camlibs/canon/usb.c.orig	Sun Aug 10 20:51:13 2003
+++ camlibs/canon/usb.c	Mon Oct 20 10:17:55 2003
@@ -356,6 +356,7 @@
 
 		case CANON_PS_S45:
 		case CANON_PS_G3:
+		case CANON_PS_G5:
 		default:
 			/* Special case: doesn't implement "get
                            picture abilities", but isn't an EOS
