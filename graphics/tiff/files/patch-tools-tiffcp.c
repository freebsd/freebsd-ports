--- tools/tiffcp.c.orig	Mon Dec 22 09:22:16 2003
+++ tools/tiffcp.c	Sat Feb  7 06:47:57 2004
@@ -1,4 +1,4 @@
-/* $Header: /cvsroot/osrs/libtiff/tools/tiffcp.c,v 1.15 2003/12/20 13:46:57 dron Exp $ */
+/* $Header: /cvsroot/osrs/libtiff/tools/tiffcp.c,v 1.18 2004/01/28 12:12:01 dron Exp $ */
 
 /*
  * Copyright (c) 1988-1997 Sam Leffler
@@ -181,7 +181,7 @@
                      fputs ("Bias image must be organized in strips\n", stderr);
                             exit (-7);
                           }
-		          TIFFGetField(bias, TIFFTAG_SAMPLESPERPIXEL, &samples);
+			  TIFFGetField(bias, TIFFTAG_SAMPLESPERPIXEL, &samples);
                           if (samples != 1) {
                      fputs ("Bias image must be monochrome\n", stderr);
                             exit (-7);
@@ -358,7 +358,7 @@
 " -t		write output in tiles",
 " -i		ignore read errors",
 " -b file[,#]	bias (dark) monochrome image to be subtracted from all others",
-" -,=%	    	use % rather than , to separate image #'s (per Note below)",           
+" -,=%		use % rather than , to separate image #'s (per Note below)",           
 "",
 " -r #		make each strip have no more than # rows",
 " -w #		set output tile width (pixels)",
@@ -500,8 +500,6 @@
 	{ TIFFTAG_PRIMARYCHROMATICITIES,(uint16) -1,TIFF_RATIONAL },
 	{ TIFFTAG_HALFTONEHINTS,	2, TIFF_SHORT },
 	{ TIFFTAG_INKSET,		1, TIFF_SHORT },
-	{ TIFFTAG_INKNAMES,		1, TIFF_ASCII },
-	{ TIFFTAG_NUMBEROFINKS,		1, TIFF_SHORT },
 	{ TIFFTAG_DOTRANGE,		2, TIFF_SHORT },
 	{ TIFFTAG_TARGETPRINTER,	1, TIFF_ASCII },
 	{ TIFFTAG_SAMPLEFORMAT,		1, TIFF_SHORT },
@@ -526,7 +524,6 @@
 tiffcp(TIFF* in, TIFF* out)
 {
 	uint16 bitspersample, samplesperpixel;
-        uint16 input_compression;
 	copyFunc cf;
 	uint32 width, length;
 	struct cpTag* p;
@@ -540,16 +537,22 @@
 	else
 		CopyField(TIFFTAG_COMPRESSION, compression);
 	if (compression == COMPRESSION_JPEG) {
+	    uint16 input_compression, input_photometric;
+
             if ( TIFFGetField( in, TIFFTAG_COMPRESSION, &input_compression )
                  && input_compression == COMPRESSION_JPEG ) {
                 TIFFSetField(in, TIFFTAG_JPEGCOLORMODE, JPEGCOLORMODE_RGB);
             }
-            if (jpegcolormode == JPEGCOLORMODE_RGB)
-		TIFFSetField(out, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_YCBCR);
-            else
-                TIFFSetField(out, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB);
+	    if (TIFFGetField(in, TIFFTAG_PHOTOMETRIC, &input_photometric)
+		&& input_photometric == PHOTOMETRIC_RGB) {
+		if (jpegcolormode == JPEGCOLORMODE_RGB)
+		    TIFFSetField(out, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_YCBCR);
+		else
+		    TIFFSetField(out, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB);
+	    }
         }
-	else if (compression == COMPRESSION_SGILOG || compression == COMPRESSION_SGILOG24)
+	else if (compression == COMPRESSION_SGILOG
+		 || compression == COMPRESSION_SGILOG24)
 		TIFFSetField(out, TIFFTAG_PHOTOMETRIC,
 		    samplesperpixel == 1 ?
 			PHOTOMETRIC_LOGL : PHOTOMETRIC_LOGLUV);
@@ -662,14 +665,75 @@
 	  if (TIFFGetField(in, TIFFTAG_ICCPROFILE, &len32, &data))
 		TIFFSetField(out, TIFFTAG_ICCPROFILE, len32, data);
 	}
+	{ uint16 ninks;
+	  const char* inknames;
+	  if (TIFFGetField(in, TIFFTAG_NUMBEROFINKS, &ninks)) {
+		TIFFSetField(out, TIFFTAG_NUMBEROFINKS, ninks);
+		if (TIFFGetField(in, TIFFTAG_INKNAMES, &inknames)) {
+		    int inknameslen = strlen(inknames) + 1;
+		    const char* cp = inknames;
+		    while (ninks > 1) {
+			    cp = strchr(cp, '\0');
+			    if (cp) {
+				    cp++;
+				    inknameslen += (strlen(cp) + 1);
+			    }
+			    ninks--;
+		    }
+		    TIFFSetField(out, TIFFTAG_INKNAMES, inknameslen, inknames);
+		}
+	  }
+	}
 	{
 	  unsigned short pg0, pg1;
-	  if (TIFFGetField(in, TIFFTAG_PAGENUMBER, &pg0, &pg1))
-		if (pageNum < 0) // only one input file
+	  if (TIFFGetField(in, TIFFTAG_PAGENUMBER, &pg0, &pg1)) {
+		if (pageNum < 0) /* only one input file */
 			TIFFSetField(out, TIFFTAG_PAGENUMBER, pg0, pg1);
 		else 
 			TIFFSetField(out, TIFFTAG_PAGENUMBER, pageNum++, 0);
+	  }
 	}
+        {
+            int  i;
+            short count;
+	    TIFFFieldInfo *xtiffFieldInfo;
+
+            count = (short) TIFFGetTagListCount(in);
+	    xtiffFieldInfo = _TIFFmalloc(count * sizeof(TIFFFieldInfo));
+            for(i = 0; i < count; i++)
+            {
+                ttag_t  tag = TIFFGetTagListEntry(in, i);
+                const TIFFFieldInfo *fld = TIFFFieldWithTag(in, tag);
+
+                if(fld == NULL)
+			continue;
+
+                _TIFFmemcpy(&xtiffFieldInfo[i], (void *)fld, sizeof(TIFFFieldInfo));
+	    }
+	    TIFFMergeFieldInfo( out, xtiffFieldInfo, count );
+	    for(i = 0; i < count; i++)
+            {
+		const TIFFFieldInfo *fld = &xtiffFieldInfo[i];
+                if(fld->field_passcount)
+                {
+			short value_count;
+			void *raw_data;
+                    
+			if(TIFFGetField(in, fld->field_tag, &value_count, &raw_data))
+				TIFFSetField(out, fld->field_tag, value_count, raw_data);
+                } 
+                else if(!fld->field_passcount
+                        && fld->field_type == TIFF_ASCII)
+                {
+                    char *data;
+                    
+                    if(TIFFGetField(in, fld->field_tag, &data))
+                       TIFFSetField(out, fld->field_tag, data);
+                }
+            }
+
+	    _TIFFfree(xtiffFieldInfo);
+        }
 	for (p = tags; p < &tags[NTAGS]; p++)
 		CopyTag(p->tag, p->count, p->type);
 
@@ -767,7 +831,7 @@
         uint32 row;
         buf = _TIFFmalloc(bufSize);
         biasBuf = _TIFFmalloc(bufSize);
-       	for (row = 0; row < imagelength; row++) {
+	for (row = 0; row < imagelength; row++) {
 	  if (TIFFReadScanline(in, buf, row, 0) < 0 && !ignore)
 		break;
 	  if (TIFFReadScanline(bias, biasBuf, row, 0) < 0 && !ignore)
@@ -1000,7 +1064,7 @@
 DECLAREreadFunc(readContigStripsIntoBuffer)
 {
 	tsize_t scanlinesize = TIFFScanlineSize(in);
-     	uint8* bufp = buf;
+	uint8* bufp = buf;
 	uint32 row;
 
 	(void) imagewidth; (void) spp;
@@ -1454,7 +1518,7 @@
 	    uint32 irps = (uint32) -1L;
 	    TIFFGetField(in, TIFFTAG_ROWSPERSTRIP, &irps);
             /* if biased, force decoded copying to allow image subtraction */
- 	    bychunk = !bias && (rowsperstrip == irps);
+	    bychunk = !bias && (rowsperstrip == irps);
 	}else{  /* either in or out is tiled */
             if (bias) {
                   fprintf(stderr,
