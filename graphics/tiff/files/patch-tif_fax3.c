CVE-2006-3464,3465
===================================================================
--- libtiff/tif_fax3.c.orig	2008-08-17 13:03:48.970994629 -0400
+++ libtiff/tif_fax3.c	2008-08-17 13:03:52.890034927 -0400
@@ -1136,6 +1136,7 @@
 Fax3VSetField(TIFF* tif, ttag_t tag, va_list ap)
 {
 	Fax3BaseState* sp = Fax3State(tif);
+	const TIFFFieldInfo* fip;
 
 	assert(sp != 0);
 	assert(sp->vsetparent != 0);
@@ -1181,7 +1182,13 @@
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
