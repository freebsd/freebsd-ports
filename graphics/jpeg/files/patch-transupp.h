--- transupp.h.orig	2009-09-03 10:54:26.000000000 +0200
+++ transupp.h	2010-01-13 09:34:06.000000000 +0100
@@ -101,7 +101,8 @@
 	JXFORM_TRANSVERSE,	/* transpose across UR-to-LL axis */
 	JXFORM_ROT_90,		/* 90-degree clockwise rotation */
 	JXFORM_ROT_180,		/* 180-degree rotation */
-	JXFORM_ROT_270		/* 270-degree clockwise (or 90 ccw) */
+	JXFORM_ROT_270,		/* 270-degree clockwise (or 90 ccw) */
+	JXFORM_DROP		/* drop */
 } JXFORM_CODE;
 
 /*
@@ -141,6 +142,10 @@
   JDIMENSION crop_yoffset;	/* Y offset of selected region */
   JCROP_CODE crop_yoffset_set;	/* (negative measures from bottom edge) */
 
+  /* Drop parameters: set by caller for drop request */
+  j_decompress_ptr drop_ptr;
+  jvirt_barray_ptr * drop_coef_arrays;
+
   /* Internal workspace: caller should not touch these */
   int num_components;		/* # of components in workspace */
   jvirt_barray_ptr * workspace_coef_arrays; /* workspace for transformations */
@@ -148,6 +153,8 @@
   JDIMENSION output_height;
   JDIMENSION x_crop_offset;	/* destination crop offsets measured in iMCUs */
   JDIMENSION y_crop_offset;
+  JDIMENSION drop_width;	/* drop dimensions measured in iMCUs */
+  JDIMENSION drop_height;
   int iMCU_sample_width;	/* destination iMCU size */
   int iMCU_sample_height;
 } jpeg_transform_info;
@@ -196,7 +203,8 @@
 typedef enum {
 	JCOPYOPT_NONE,		/* copy no optional markers */
 	JCOPYOPT_COMMENTS,	/* copy only comment (COM) markers */
-	JCOPYOPT_ALL		/* copy all optional markers */
+	JCOPYOPT_ALL,		/* copy all optional markers */
+	JCOPYOPT_EXIF		/* copy Exif APP1 marker */
 } JCOPY_OPTION;
 
 #define JCOPYOPT_DEFAULT  JCOPYOPT_COMMENTS	/* recommended default */
