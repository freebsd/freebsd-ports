revision 1.41
date: 2015-12-27 16:25:11 +0000;  author: erouault;  state: Exp;  lines: +45 -12;  commitid: gXczlJDfVlBdzBOy;
* libtiff/tif_luv.c: fix potential out-of-bound writes in decode
functions in non debug builds by replacing assert()s by regular if
checks (bugzilla #2522).
Fix potential out-of-bound reads in case of short input data.

Index: libtiff/tif_luv.c
===================================================================
RCS file: /cvs/maptools/cvsroot/libtiff/libtiff/tif_luv.c,v
retrieving revision 1.40
retrieving revision 1.41
diff -u -r1.40 -r1.41
--- libtiff/tif_luv.c	21 Jun 2015 01:09:09 -0000	1.40
+++ libtiff/tif_luv.c	27 Dec 2015 16:25:11 -0000	1.41
@@ -1,4 +1,4 @@
-/* $Id: tif_luv.c,v 1.40 2015-06-21 01:09:09 bfriesen Exp $ */
+/* $Id: tif_luv.c,v 1.41 2015-12-27 16:25:11 erouault Exp $ */
 
 /*
  * Copyright (c) 1997 Greg Ward Larson
@@ -202,7 +202,11 @@
 	if (sp->user_datafmt == SGILOGDATAFMT_16BIT)
 		tp = (int16*) op;
 	else {
-		assert(sp->tbuflen >= npixels);
+		if(sp->tbuflen < npixels) {
+			TIFFErrorExt(tif->tif_clientdata, module,
+						 "Translation buffer too short");
+			return (0);
+		}
 		tp = (int16*) sp->tbuf;
 	}
 	_TIFFmemset((void*) tp, 0, npixels*sizeof (tp[0]));
@@ -211,9 +215,11 @@
 	cc = tif->tif_rawcc;
 	/* get each byte string */
 	for (shft = 2*8; (shft -= 8) >= 0; ) {
-		for (i = 0; i < npixels && cc > 0; )
+		for (i = 0; i < npixels && cc > 0; ) {
 			if (*bp >= 128) {		/* run */
-				rc = *bp++ + (2-128);   /* TODO: potential input buffer overrun when decoding corrupt or truncated data */
+				if( cc < 2 )
+					break;
+				rc = *bp++ + (2-128);
 				b = (int16)(*bp++ << shft);
 				cc -= 2;
 				while (rc-- && i < npixels)
@@ -223,6 +229,7 @@
 				while (--cc && rc-- && i < npixels)
 					tp[i++] |= (int16)*bp++ << shft;
 			}
+		}
 		if (i != npixels) {
 #if defined(__WIN32__) && (defined(_MSC_VER) || defined(__MINGW32__))
 			TIFFErrorExt(tif->tif_clientdata, module,
@@ -268,13 +275,17 @@
 	if (sp->user_datafmt == SGILOGDATAFMT_RAW)
 		tp = (uint32 *)op;
 	else {
-		assert(sp->tbuflen >= npixels);
+		if(sp->tbuflen < npixels) {
+			TIFFErrorExt(tif->tif_clientdata, module,
+						 "Translation buffer too short");
+			return (0);
+		}
 		tp = (uint32 *) sp->tbuf;
 	}
 	/* copy to array of uint32 */
 	bp = (unsigned char*) tif->tif_rawcp;
 	cc = tif->tif_rawcc;
-	for (i = 0; i < npixels && cc > 0; i++) {
+	for (i = 0; i < npixels && cc >= 3; i++) {
 		tp[i] = bp[0] << 16 | bp[1] << 8 | bp[2];
 		bp += 3;
 		cc -= 3;
@@ -325,7 +336,11 @@
 	if (sp->user_datafmt == SGILOGDATAFMT_RAW)
 		tp = (uint32*) op;
 	else {
-		assert(sp->tbuflen >= npixels);
+		if(sp->tbuflen < npixels) {
+			TIFFErrorExt(tif->tif_clientdata, module,
+						 "Translation buffer too short");
+			return (0);
+		}
 		tp = (uint32*) sp->tbuf;
 	}
 	_TIFFmemset((void*) tp, 0, npixels*sizeof (tp[0]));
@@ -334,11 +349,13 @@
 	cc = tif->tif_rawcc;
 	/* get each byte string */
 	for (shft = 4*8; (shft -= 8) >= 0; ) {
-		for (i = 0; i < npixels && cc > 0; )
+		for (i = 0; i < npixels && cc > 0; ) {
 			if (*bp >= 128) {		/* run */
+				if( cc < 2 )
+					break;
 				rc = *bp++ + (2-128);
 				b = (uint32)*bp++ << shft;
-				cc -= 2;                /* TODO: potential input buffer overrun when decoding corrupt or truncated data */
+				cc -= 2;
 				while (rc-- && i < npixels)
 					tp[i++] |= b;
 			} else {			/* non-run */
@@ -346,6 +363,7 @@
 				while (--cc && rc-- && i < npixels)
 					tp[i++] |= (uint32)*bp++ << shft;
 			}
+		}
 		if (i != npixels) {
 #if defined(__WIN32__) && (defined(_MSC_VER) || defined(__MINGW32__))
 			TIFFErrorExt(tif->tif_clientdata, module,
@@ -413,6 +431,7 @@
 static int
 LogL16Encode(TIFF* tif, uint8* bp, tmsize_t cc, uint16 s)
 {
+	static const char module[] = "LogL16Encode";
 	LogLuvState* sp = EncoderState(tif);
 	int shft;
 	tmsize_t i;
@@ -433,7 +452,11 @@
 		tp = (int16*) bp;
 	else {
 		tp = (int16*) sp->tbuf;
-		assert(sp->tbuflen >= npixels);
+		if(sp->tbuflen < npixels) {
+			TIFFErrorExt(tif->tif_clientdata, module,
+						 "Translation buffer too short");
+			return (0);
+		}
 		(*sp->tfunc)(sp, bp, npixels);
 	}
 	/* compress each byte string */
@@ -506,6 +529,7 @@
 static int
 LogLuvEncode24(TIFF* tif, uint8* bp, tmsize_t cc, uint16 s)
 {
+	static const char module[] = "LogLuvEncode24";
 	LogLuvState* sp = EncoderState(tif);
 	tmsize_t i;
 	tmsize_t npixels;
@@ -521,7 +545,11 @@
 		tp = (uint32*) bp;
 	else {
 		tp = (uint32*) sp->tbuf;
-		assert(sp->tbuflen >= npixels);
+		if(sp->tbuflen < npixels) {
+			TIFFErrorExt(tif->tif_clientdata, module,
+						 "Translation buffer too short");
+			return (0);
+		}
 		(*sp->tfunc)(sp, bp, npixels);
 	}
 	/* write out encoded pixels */
@@ -553,6 +581,7 @@
 static int
 LogLuvEncode32(TIFF* tif, uint8* bp, tmsize_t cc, uint16 s)
 {
+	static const char module[] = "LogLuvEncode32";
 	LogLuvState* sp = EncoderState(tif);
 	int shft;
 	tmsize_t i;
@@ -574,7 +603,11 @@
 		tp = (uint32*) bp;
 	else {
 		tp = (uint32*) sp->tbuf;
-		assert(sp->tbuflen >= npixels);
+		if(sp->tbuflen < npixels) {
+			TIFFErrorExt(tif->tif_clientdata, module,
+						 "Translation buffer too short");
+			return (0);
+		}
 		(*sp->tfunc)(sp, bp, npixels);
 	}
 	/* compress each byte string */
