revision 1.17
date: 2015-12-27 16:55:20 +0000;  author: erouault;  state: Exp;  lines: +9 -3;  commitid: 4yLOaM0uFVPyJBOy;
* libtiff/tif_next.c: fix potential out-of-bound write in NeXTDecode()
triggered by http://lcamtuf.coredump.cx/afl/vulns/libtiff5.tif
(bugzilla #2508)

Index: libtiff/tif_next.c
===================================================================
RCS file: /cvs/maptools/cvsroot/libtiff/libtiff/tif_next.c,v
retrieving revision 1.16
retrieving revision 1.17
diff -u -r1.16 -r1.17
--- libtiff/tif_next.c	29 Dec 2014 12:09:11 -0000	1.16
+++ libtiff/tif_next.c	27 Dec 2015 16:55:20 -0000	1.17
@@ -1,4 +1,4 @@
-/* $Id: tif_next.c,v 1.16 2014-12-29 12:09:11 erouault Exp $ */
+/* $Id: tif_next.c,v 1.17 2015-12-27 16:55:20 erouault Exp $ */
 
 /*
  * Copyright (c) 1988-1997 Sam Leffler
@@ -37,7 +37,7 @@
 	case 0:	op[0]  = (unsigned char) ((v) << 6); break;	\
 	case 1:	op[0] |= (v) << 4; break;	\
 	case 2:	op[0] |= (v) << 2; break;	\
-	case 3:	*op++ |= (v);	   break;	\
+	case 3:	*op++ |= (v);	   op_offset++; break;	\
 	}					\
 }
 
@@ -106,6 +106,7 @@
 			uint32 imagewidth = tif->tif_dir.td_imagewidth;
             if( isTiled(tif) )
                 imagewidth = tif->tif_dir.td_tilewidth;
+            tmsize_t op_offset = 0;
 
 			/*
 			 * The scanline is composed of a sequence of constant
@@ -122,10 +123,15 @@
 				 * bounds, potentially resulting in a security
 				 * issue.
 				 */
-				while (n-- > 0 && npixels < imagewidth)
+				while (n-- > 0 && npixels < imagewidth && op_offset < scanline)
 					SETPIXEL(op, grey);
 				if (npixels >= imagewidth)
 					break;
+                if (op_offset >= scanline ) {
+                    TIFFErrorExt(tif->tif_clientdata, module, "Invalid data for scanline %ld",
+                        (long) tif->tif_row);
+                    return (0);
+                }
 				if (cc == 0)
 					goto bad;
 				n = *bp++, cc--;
