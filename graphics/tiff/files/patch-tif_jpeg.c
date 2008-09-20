CVE-2006-3460,3464,3465
===================================================================
--- libtiff/tif_jpeg.c.orig	2008-08-17 13:03:48.974994391 -0400
+++ libtiff/tif_jpeg.c	2008-08-17 13:03:52.894064968 -0400
@@ -722,15 +722,31 @@
 		segment_width = TIFFhowmany(segment_width, sp->h_sampling);
 		segment_height = TIFFhowmany(segment_height, sp->v_sampling);
 	}
-	if (sp->cinfo.d.image_width != segment_width ||
-	    sp->cinfo.d.image_height != segment_height) {
+	if (sp->cinfo.d.image_width < segment_width ||
+	    sp->cinfo.d.image_height < segment_height) {
 		TIFFWarningExt(tif->tif_clientdata, module,
                  "Improper JPEG strip/tile size, expected %dx%d, got %dx%d",
                           segment_width, 
                           segment_height,
                           sp->cinfo.d.image_width, 
                           sp->cinfo.d.image_height);
+	} 
+	
+	if (sp->cinfo.d.image_width > segment_width ||
+			sp->cinfo.d.image_height > segment_height) {
+		/*
+		 * This case could be dangerous, if the strip or tile size has been
+		 * reported as less than the amount of data jpeg will return, some
+		 * potential security issues arise. Catch this case and error out.
+		 * -- taviso@google.com 14 Jun 2006
+		 */
+		TIFFErrorExt(tif->tif_clientdata, module, 
+			"JPEG strip/tile size exceeds expected dimensions,"
+			"expected %dx%d, got %dx%d", segment_width, segment_height,
+			sp->cinfo.d.image_width, sp->cinfo.d.image_height);
+		return (0);
 	}
+
 	if (sp->cinfo.d.num_components !=
 	    (td->td_planarconfig == PLANARCONFIG_CONTIG ?
 	     td->td_samplesperpixel : 1)) {
@@ -761,6 +777,22 @@
                                     sp->cinfo.d.comp_info[0].v_samp_factor,
                                     sp->h_sampling, sp->v_sampling);
 
+				/*
+				 * There are potential security issues here for decoders that
+				 * have already allocated buffers based on the expected sampling
+				 * factors. Lets check the sampling factors dont exceed what
+				 * we were expecting.
+				 * -- taviso@google.com 14 June 2006
+				 */
+				if (sp->cinfo.d.comp_info[0].h_samp_factor > sp->h_sampling ||
+					sp->cinfo.d.comp_info[0].v_samp_factor > sp->v_sampling) {
+						TIFFErrorExt(tif->tif_clientdata, module,
+							"Cannot honour JPEG sampling factors that"
+							" exceed those specified.");
+						return (0);
+				}
+
+
 			    /*
 			     * XXX: Files written by the Intergraph software
 			     * has different sampling factors stored in the
@@ -1521,15 +1553,18 @@
 {
 	JPEGState *sp = JState(tif);
 	
-	assert(sp != 0);
+	/* assert(sp != 0); */
 
 	tif->tif_tagmethods.vgetfield = sp->vgetparent;
 	tif->tif_tagmethods.vsetfield = sp->vsetparent;
 
-	if( sp->cinfo_initialized )
-	    TIFFjpeg_destroy(sp);	/* release libjpeg resources */
-	if (sp->jpegtables)		/* tag value */
-		_TIFFfree(sp->jpegtables);
+	if (sp != NULL) {
+		if( sp->cinfo_initialized )
+		    TIFFjpeg_destroy(sp);	/* release libjpeg resources */
+		if (sp->jpegtables)		/* tag value */
+			_TIFFfree(sp->jpegtables);
+	}
+
 	_TIFFfree(tif->tif_data);	/* release local state */
 	tif->tif_data = NULL;
 
@@ -1541,6 +1576,7 @@
 {
 	JPEGState* sp = JState(tif);
 	TIFFDirectory* td = &tif->tif_dir;
+	const TIFFFieldInfo* fip;
 	uint32 v32;
 
 	assert(sp != NULL);
@@ -1606,7 +1642,13 @@
 	default:
 		return (*sp->vsetparent)(tif, tag, ap);
 	}
-	TIFFSetFieldBit(tif, _TIFFFieldWithTag(tif, tag)->field_bit);
+
+	if ((fip = _TIFFFieldWithTag(tif, tag))) {
+		TIFFSetFieldBit(tif, fip->field_bit);
+	} else {
+		return (0);
+	}
+
 	tif->tif_flags |= TIFF_DIRTYDIRECT;
 	return (1);
 }
@@ -1726,7 +1768,11 @@
 {
 	JPEGState* sp = JState(tif);
 
-	assert(sp != NULL);
+	/* assert(sp != NULL); */
+	if (sp == NULL) {
+		TIFFWarningExt(tif->tif_clientdata, "JPEGPrintDir", "Unknown JPEGState");
+		return;
+	}
 
 	(void) flags;
 	if (TIFFFieldSet(tif,FIELD_JPEGTABLES))
