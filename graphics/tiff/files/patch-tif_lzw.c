CVE-2008-2327
===================================================================
--- libtiff/tif_lzw.c.orig	2008-08-17 13:03:49.090994393 -0400
+++ libtiff/tif_lzw.c	2008-08-17 13:03:52.354994400 -0400
@@ -237,6 +237,13 @@
                     sp->dec_codetab[code].length = 1;
                     sp->dec_codetab[code].next = NULL;
                 } while (code--);
+                /*
+                 * Zero-out the unused entries
+                 */
+                 _TIFFmemset(&sp->dec_codetab[CODE_CLEAR], 0,
+                 (CODE_FIRST-CODE_CLEAR)*sizeof (code_t));
+
+
 	}
 	return (1);
 }
@@ -408,12 +415,20 @@
 			break;
 		if (code == CODE_CLEAR) {
 			free_entp = sp->dec_codetab + CODE_FIRST;
+			 _TIFFmemset(free_entp, 0, (CSIZE-CODE_FIRST)*sizeof (code_t));
 			nbits = BITS_MIN;
 			nbitsmask = MAXCODE(BITS_MIN);
 			maxcodep = sp->dec_codetab + nbitsmask-1;
 			NextCode(tif, sp, bp, code, GetNextCode);
 			if (code == CODE_EOI)
 				break;
+			 if (code == CODE_CLEAR) {
+				 TIFFErrorExt(tif->tif_clientdata, tif->tif_name,
+				 "LZWDecode: Corrupted LZW table at scanline %d",
+				 tif->tif_row);
+				 return (0);
+			 }
+
 			*op++ = (char)code, occ--;
 			oldcodep = sp->dec_codetab + code;
 			continue;
@@ -604,12 +619,20 @@
 			break;
 		if (code == CODE_CLEAR) {
 			free_entp = sp->dec_codetab + CODE_FIRST;
+			 _TIFFmemset(free_entp, 0, (CSIZE-CODE_FIRST)*sizeof (code_t));
 			nbits = BITS_MIN;
 			nbitsmask = MAXCODE(BITS_MIN);
 			maxcodep = sp->dec_codetab + nbitsmask;
 			NextCode(tif, sp, bp, code, GetNextCodeCompat);
 			if (code == CODE_EOI)
 				break;
+			 if (code == CODE_CLEAR) {
+				 TIFFErrorExt(tif->tif_clientdata, tif->tif_name,
+				 "LZWDecode: Corrupted LZW table at scanline %d",
+				 tif->tif_row);
+				 return (0);
+			 }
+
 			*op++ = code, occ--;
 			oldcodep = sp->dec_codetab + code;
 			continue;
