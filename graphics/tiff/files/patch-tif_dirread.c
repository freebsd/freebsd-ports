CVE-2006-3459,3463,3464,3465 
===================================================================
--- libtiff/tif_dirread.c.orig	2008-08-17 13:03:48.962994506 -0400
+++ libtiff/tif_dirread.c	2008-08-17 13:03:52.890034927 -0400
@@ -29,6 +29,9 @@
  *
  * Directory Read Support Routines.
  */
+
+#include <limits.h>
+
 #include "tiffiop.h"
 
 #define	IGNORE	0		/* tag placeholder used below */
@@ -81,6 +84,7 @@
 	uint16 dircount;
 	toff_t nextdiroff;
 	int diroutoforderwarning = 0;
+	int compressionknown = 0;
 	toff_t* new_dirlist;
 
 	tif->tif_diroff = tif->tif_nextdiroff;
@@ -147,13 +151,20 @@
 	} else {
 		toff_t off = tif->tif_diroff;
 
-		if (off + sizeof (uint16) > tif->tif_size) {
-			TIFFErrorExt(tif->tif_clientdata, module,
-			    "%s: Can not read TIFF directory count",
-                            tif->tif_name);
-			return (0);
+		/*
+		 * Check for integer overflow when validating the dir_off, otherwise
+		 * a very high offset may cause an OOB read and crash the client.
+		 * -- taviso@google.com, 14 Jun 2006.
+		 */
+		if (off + sizeof (uint16) > tif->tif_size || 
+			off > (UINT_MAX - sizeof(uint16))) {
+				TIFFErrorExt(tif->tif_clientdata, module,
+				    "%s: Can not read TIFF directory count",
+				    tif->tif_name);
+				return (0);
 		} else
-			_TIFFmemcpy(&dircount, tif->tif_base + off, sizeof (uint16));
+			_TIFFmemcpy(&dircount, tif->tif_base + off,
+					sizeof (uint16));
 		off += sizeof (uint16);
 		if (tif->tif_flags & TIFF_SWAB)
 			TIFFSwabShort(&dircount);
@@ -254,6 +265,7 @@
 		while (fix < tif->tif_nfields &&
 		       tif->tif_fieldinfo[fix]->field_tag < dp->tdir_tag)
 			fix++;
+
 		if (fix >= tif->tif_nfields ||
 		    tif->tif_fieldinfo[fix]->field_tag != dp->tdir_tag) {
 
@@ -264,17 +276,23 @@
 						       dp->tdir_tag,
 						       dp->tdir_tag,
 						       dp->tdir_type);
-
-                    TIFFMergeFieldInfo(tif,
-                                       _TIFFCreateAnonFieldInfo(tif,
-						dp->tdir_tag,
-						(TIFFDataType) dp->tdir_type),
-				       1 );
+					/*
+					 * creating anonymous fields prior to knowing the compression
+					 * algorithm (ie, when the field info has been merged) could cause
+					 * crashes with pathological directories.
+					 * -- taviso@google.com 15 Jun 2006
+					 */
+					if (compressionknown)
+			                    TIFFMergeFieldInfo(tif, _TIFFCreateAnonFieldInfo(tif, dp->tdir_tag, 
+						(TIFFDataType) dp->tdir_type), 1 );
+					else goto ignore;
+		    
                     fix = 0;
                     while (fix < tif->tif_nfields &&
                            tif->tif_fieldinfo[fix]->field_tag < dp->tdir_tag)
 			fix++;
 		}
+		
 		/*
 		 * Null out old tags that we ignore.
 		 */
@@ -326,6 +344,7 @@
 				    dp->tdir_type, dp->tdir_offset);
 				if (!TIFFSetField(tif, dp->tdir_tag, (uint16)v))
 					goto bad;
+				else compressionknown++;
 				break;
 			/* XXX: workaround for broken TIFFs */
 			} else if (dp->tdir_type == TIFF_LONG) {
@@ -540,6 +559,7 @@
 	 * Attempt to deal with a missing StripByteCounts tag.
 	 */
 	if (!TIFFFieldSet(tif, FIELD_STRIPBYTECOUNTS)) {
+		const TIFFFieldInfo* fip = _TIFFFieldWithTag(tif, TIFFTAG_STRIPBYTECOUNTS);
 		/*
 		 * Some manufacturers violate the spec by not giving
 		 * the size of the strips.  In this case, assume there
@@ -556,7 +576,7 @@
 			"%s: TIFF directory is missing required "
 			"\"%s\" field, calculating from imagelength",
 			tif->tif_name,
-		        _TIFFFieldWithTag(tif,TIFFTAG_STRIPBYTECOUNTS)->field_name);
+		        fip ? fip->field_name : "Unknown");
 		if (EstimateStripByteCounts(tif, dir, dircount) < 0)
 		    goto bad;
 /* 
@@ -580,6 +600,7 @@
 	} else if (td->td_nstrips == 1 
                    && td->td_stripoffset[0] != 0 
                    && BYTECOUNTLOOKSBAD) {
+		const TIFFFieldInfo* fip = _TIFFFieldWithTag(tif, TIFFTAG_STRIPBYTECOUNTS);
 		/*
 		 * XXX: Plexus (and others) sometimes give a value of zero for
 		 * a tag when they don't know what the correct value is!  Try
@@ -589,13 +610,14 @@
 		TIFFWarningExt(tif->tif_clientdata, module,
 	"%s: Bogus \"%s\" field, ignoring and calculating from imagelength",
                             tif->tif_name,
-		            _TIFFFieldWithTag(tif,TIFFTAG_STRIPBYTECOUNTS)->field_name);
+		            fip ? fip->field_name : "Unknown");
 		if(EstimateStripByteCounts(tif, dir, dircount) < 0)
 		    goto bad;
 	} else if (td->td_planarconfig == PLANARCONFIG_CONTIG
 		   && td->td_nstrips > 2
 		   && td->td_compression == COMPRESSION_NONE
 		   && td->td_stripbytecount[0] != td->td_stripbytecount[1]) {
+		const TIFFFieldInfo* fip = _TIFFFieldWithTag(tif, TIFFTAG_STRIPBYTECOUNTS);
 		/*
 		 * XXX: Some vendors fill StripByteCount array with absolutely
 		 * wrong values (it can be equal to StripOffset array, for
@@ -604,7 +626,7 @@
 		TIFFWarningExt(tif->tif_clientdata, module,
 	"%s: Wrong \"%s\" field, ignoring and calculating from imagelength",
                             tif->tif_name,
-		            _TIFFFieldWithTag(tif,TIFFTAG_STRIPBYTECOUNTS)->field_name);
+		            fip ? fip->field_name : "Unknown");
 		if (EstimateStripByteCounts(tif, dir, dircount) < 0)
 		    goto bad;
 	}
@@ -870,7 +892,13 @@
 
 	register TIFFDirEntry *dp;
 	register TIFFDirectory *td = &tif->tif_dir;
-	uint16 i;
+	
+	/* i is used to iterate over td->td_nstrips, so must be
+	 * at least the same width.
+	 * -- taviso@google.com 15 Jun 2006
+	 */
+
+	uint32 i;
 
 	if (td->td_stripbytecount)
 		_TIFFfree(td->td_stripbytecount);
@@ -947,16 +975,18 @@
 static int
 CheckDirCount(TIFF* tif, TIFFDirEntry* dir, uint32 count)
 {
+	const TIFFFieldInfo* fip = _TIFFFieldWithTag(tif, dir->tdir_tag);
+
 	if (count > dir->tdir_count) {
 		TIFFWarningExt(tif->tif_clientdata, tif->tif_name,
 	"incorrect count for field \"%s\" (%lu, expecting %lu); tag ignored",
-		    _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name,
+		    fip ? fip->field_name : "Unknown",
 		    dir->tdir_count, count);
 		return (0);
 	} else if (count < dir->tdir_count) {
 		TIFFWarningExt(tif->tif_clientdata, tif->tif_name,
 	"incorrect count for field \"%s\" (%lu, expecting %lu); tag trimmed",
-		    _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name,
+		    fip ? fip->field_name : "Unknown",
 		    dir->tdir_count, count);
 		return (1);
 	}
@@ -970,6 +1000,7 @@
 TIFFFetchData(TIFF* tif, TIFFDirEntry* dir, char* cp)
 {
 	int w = TIFFDataWidth((TIFFDataType) dir->tdir_type);
+	const TIFFFieldInfo* fip = _TIFFFieldWithTag(tif, dir->tdir_tag);
 	tsize_t cc = dir->tdir_count * w;
 
 	/* Check for overflow. */
@@ -1013,7 +1044,7 @@
 bad:
 	TIFFErrorExt(tif->tif_clientdata, tif->tif_name,
 		     "Error fetching data for field \"%s\"",
-		     _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name);
+		     fip ? fip->field_name : "Unknown");
 	return (tsize_t) 0;
 }
 
@@ -1039,10 +1070,12 @@
 static int
 cvtRational(TIFF* tif, TIFFDirEntry* dir, uint32 num, uint32 denom, float* rv)
 {
+	const TIFFFieldInfo* fip;
 	if (denom == 0) {
+		fip = _TIFFFieldWithTag(tif, dir->tdir_tag);
 		TIFFErrorExt(tif->tif_clientdata, tif->tif_name,
 		    "%s: Rational with zero denominator (num = %lu)",
-		    _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name, num);
+		    fip ? fip->field_name : "Unknown", num);
 		return (0);
 	} else {
 		if (dir->tdir_type == TIFF_RATIONAL)
@@ -1159,6 +1192,20 @@
 static int
 TIFFFetchShortPair(TIFF* tif, TIFFDirEntry* dir)
 {
+	/*
+	 * Prevent overflowing the v stack arrays below by performing a sanity
+	 * check on tdir_count, this should never be greater than two.
+	 * -- taviso@google.com 14 Jun 2006.
+	 */
+	if (dir->tdir_count > 2) {
+		const TIFFFieldInfo* fip = _TIFFFieldWithTag(tif, dir->tdir_tag);
+		TIFFWarningExt(tif->tif_clientdata, tif->tif_name,
+				"unexpected count for field \"%s\", %lu, expected 2; ignored.",
+				fip ? fip->field_name : "Unknown",
+				dir->tdir_count);
+		return 0;
+	}
+
 	switch (dir->tdir_type) {
 		case TIFF_BYTE:
 		case TIFF_SBYTE:
@@ -1329,14 +1376,15 @@
 	case TIFF_DOUBLE:
 		return (TIFFFetchDoubleArray(tif, dir, (double*) v));
 	default:
+		{ const TIFFFieldInfo* fip = _TIFFFieldWithTag(tif, dir->tdir_tag);
 		/* TIFF_NOTYPE */
 		/* TIFF_ASCII */
 		/* TIFF_UNDEFINED */
 		TIFFErrorExt(tif->tif_clientdata, tif->tif_name,
 			     "cannot read TIFF_ANY type %d for field \"%s\"",
 			     dir->tdir_type,
-			     _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name);
-		return (0);
+			     fip ? fip->field_name : "Unknown");
+		return (0); }
 	}
 	return (1);
 }
@@ -1351,6 +1399,9 @@
 	int ok = 0;
 	const TIFFFieldInfo* fip = _TIFFFieldWithTag(tif, dp->tdir_tag);
 
+	if (fip == NULL) {
+		return (0);
+	}
 	if (dp->tdir_count > 1) {		/* array of values */
 		char* cp = NULL;
 
@@ -1493,6 +1544,7 @@
 TIFFFetchPerSampleShorts(TIFF* tif, TIFFDirEntry* dir, uint16* pl)
 {
     uint16 samples = tif->tif_dir.td_samplesperpixel;
+    const TIFFFieldInfo* fip;
     int status = 0;
 
     if (CheckDirCount(tif, dir, (uint32) samples)) {
@@ -1510,9 +1562,10 @@
 
             for (i = 1; i < check_count; i++)
                 if (v[i] != v[0]) {
+				fip = _TIFFFieldWithTag(tif, dir->tdir_tag);
 					TIFFErrorExt(tif->tif_clientdata, tif->tif_name,
                               "Cannot handle different per-sample values for field \"%s\"",
-                              _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name);
+                              fip ? fip->field_name : "Unknown");
                     goto bad;
                 }
             *pl = v[0];
@@ -1534,6 +1587,7 @@
 TIFFFetchPerSampleLongs(TIFF* tif, TIFFDirEntry* dir, uint32* pl)
 {
     uint16 samples = tif->tif_dir.td_samplesperpixel;
+    const TIFFFieldInfo* fip;
     int status = 0;
 
     if (CheckDirCount(tif, dir, (uint32) samples)) {
@@ -1551,9 +1605,10 @@
                 check_count = samples;
             for (i = 1; i < check_count; i++)
                 if (v[i] != v[0]) {
+				fip = _TIFFFieldWithTag(tif, dir->tdir_tag);
 					TIFFErrorExt(tif->tif_clientdata, tif->tif_name,
                               "Cannot handle different per-sample values for field \"%s\"",
-                              _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name);
+                              fip ? fip->field_name : "Unknown");
                     goto bad;
                 }
             *pl = v[0];
@@ -1574,6 +1629,7 @@
 TIFFFetchPerSampleAnys(TIFF* tif, TIFFDirEntry* dir, double* pl)
 {
     uint16 samples = tif->tif_dir.td_samplesperpixel;
+    const TIFFFieldInfo* fip;
     int status = 0;
 
     if (CheckDirCount(tif, dir, (uint32) samples)) {
@@ -1591,9 +1647,10 @@
 
             for (i = 1; i < check_count; i++)
                 if (v[i] != v[0]) {
+		    fip = _TIFFFieldWithTag(tif, dir->tdir_tag);
                     TIFFErrorExt(tif->tif_clientdata, tif->tif_name,
                               "Cannot handle different per-sample values for field \"%s\"",
-                              _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name);
+                              fip ? fip->field_name : "Unknown");
                     goto bad;
                 }
             *pl = v[0];
