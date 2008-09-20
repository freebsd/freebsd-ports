CVE-2006-3464,3465
===================================================================
--- libtiff/tif_dir.c.orig	2008-08-17 13:03:48.954994295 -0400
+++ libtiff/tif_dir.c	2008-08-17 13:03:52.881994558 -0400
@@ -122,6 +122,7 @@
 {
 	static const char module[] = "_TIFFVSetField";
 	
+	const TIFFFieldInfo* fip = _TIFFFindFieldInfo(tif, tag, TIFF_ANY);
 	TIFFDirectory* td = &tif->tif_dir;
 	int status = 1;
 	uint32 v32, i, v;
@@ -195,10 +196,12 @@
 		break;
 	case TIFFTAG_ORIENTATION:
 		v = va_arg(ap, uint32);
+		const TIFFFieldInfo* fip;
 		if (v < ORIENTATION_TOPLEFT || ORIENTATION_LEFTBOT < v) {
+			fip = _TIFFFieldWithTag(tif, tag);
 			TIFFWarningExt(tif->tif_clientdata, tif->tif_name,
 			    "Bad value %lu for \"%s\" tag ignored",
-			    v, _TIFFFieldWithTag(tif, tag)->field_name);
+			    v, fip ? fip->field_name : "Unknown");
 		} else
 			td->td_orientation = (uint16) v;
 		break;
@@ -387,11 +390,15 @@
 	     * happens, for example, when tiffcp is used to convert between
 	     * compression schemes and codec-specific tags are blindly copied.
              */
+	    /* 
+	     * better not dereference fip if it is NULL.
+	     * -- taviso@google.com 15 Jun 2006
+	     */
             if(fip == NULL || fip->field_bit != FIELD_CUSTOM) {
 		TIFFErrorExt(tif->tif_clientdata, module,
 		    "%s: Invalid %stag \"%s\" (not supported by codec)",
 		    tif->tif_name, isPseudoTag(tag) ? "pseudo-" : "",
-		    _TIFFFieldWithTag(tif, tag)->field_name);
+		    fip ? fip->field_name : "Unknown");
 		status = 0;
 		break;
             }
@@ -468,7 +475,7 @@
 	    if (fip->field_type == TIFF_ASCII)
 		    _TIFFsetString((char **)&tv->value, va_arg(ap, char *));
 	    else {
-                tv->value = _TIFFmalloc(tv_size * tv->count);
+                tv->value = _TIFFCheckMalloc(tif, tv_size, tv->count, "Tag Value");
 		if (!tv->value) {
 		    status = 0;
 		    goto end;
@@ -563,7 +570,7 @@
           }
 	}
 	if (status) {
-		TIFFSetFieldBit(tif, _TIFFFieldWithTag(tif, tag)->field_bit);
+		TIFFSetFieldBit(tif, fip->field_bit);
 		tif->tif_flags |= TIFF_DIRTYDIRECT;
 	}
 
@@ -572,12 +579,12 @@
 	return (status);
 badvalue:
 	TIFFErrorExt(tif->tif_clientdata, module, "%s: Bad value %d for \"%s\"",
-		  tif->tif_name, v, _TIFFFieldWithTag(tif, tag)->field_name);
+		  tif->tif_name, v, fip ? fip->field_name : "Unknown");
 	va_end(ap);
 	return (0);
 badvalue32:
 	TIFFErrorExt(tif->tif_clientdata, module, "%s: Bad value %ld for \"%s\"",
-		   tif->tif_name, v32, _TIFFFieldWithTag(tif, tag)->field_name);
+		   tif->tif_name, v32, fip ? fip->field_name : "Unknown");
 	va_end(ap);
 	return (0);
 }
@@ -813,12 +820,16 @@
              * If the client tries to get a tag that is not valid
              * for the image's codec then we'll arrive here.
              */
+	    /*
+	     * dont dereference fip if it's NULL.
+	     * -- taviso@google.com 15 Jun 2006
+	     */
             if( fip == NULL || fip->field_bit != FIELD_CUSTOM )
             {
 				TIFFErrorExt(tif->tif_clientdata, "_TIFFVGetField",
                           "%s: Invalid %stag \"%s\" (not supported by codec)",
                           tif->tif_name, isPseudoTag(tag) ? "pseudo-" : "",
-                          _TIFFFieldWithTag(tif, tag)->field_name);
+                          fip ? fip->field_name : "Unknown");
                 ret_val = 0;
                 break;
             }
