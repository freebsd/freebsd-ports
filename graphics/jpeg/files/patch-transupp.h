--- transupp.h.orig	2003-09-21 23:01:30.000000000 +0200
+++ transupp.h	2009-07-01 08:54:49.000000000 +0200
@@ -96,7 +96,8 @@
 	JXFORM_TRANSVERSE,	/* transpose across UR-to-LL axis */
 	JXFORM_ROT_90,		/* 90-degree clockwise rotation */
 	JXFORM_ROT_180,		/* 180-degree rotation */
-	JXFORM_ROT_270		/* 270-degree clockwise (or 90 ccw) */
+	JXFORM_ROT_270,		/* 270-degree clockwise (or 90 ccw) */
+	JXFORM_DROP		/* drop */
 } JXFORM_CODE;
 
 /*
@@ -136,6 +137,10 @@
   JDIMENSION crop_yoffset;	/* Y offset of selected region */
   JCROP_CODE crop_yoffset_set;	/* (negative measures from bottom edge) */
 
+  /* Drop parameters: set by caller for drop request */
+  j_decompress_ptr drop_ptr;
+  jvirt_barray_ptr * drop_coef_arrays;
+
   /* Internal workspace: caller should not touch these */
   int num_components;		/* # of components in workspace */
   jvirt_barray_ptr * workspace_coef_arrays; /* workspace for transformations */
@@ -143,6 +148,8 @@
   JDIMENSION output_height;
   JDIMENSION x_crop_offset;	/* destination crop offsets measured in iMCUs */
   JDIMENSION y_crop_offset;
+  JDIMENSION drop_width;	/* drop dimensions measured in iMCUs */
+  JDIMENSION drop_height;
   int max_h_samp_factor;	/* destination iMCU size */
   int max_v_samp_factor;
 } jpeg_transform_info;
@@ -191,7 +198,8 @@
 typedef enum {
 	JCOPYOPT_NONE,		/* copy no optional markers */
 	JCOPYOPT_COMMENTS,	/* copy only comment (COM) markers */
-	JCOPYOPT_ALL		/* copy all optional markers */
+	JCOPYOPT_ALL,		/* copy all optional markers */
+	JCOPYOPT_EXIF		/* copy Exif APP1 marker */
 } JCOPY_OPTION;
 
 #define JCOPYOPT_DEFAULT  JCOPYOPT_COMMENTS	/* recommended default */
