--- transupp.h.orig	Wed Jul 23 22:39:12 1997
+++ transupp.h	Fri Jun  4 15:07:31 2004
@@ -1,7 +1,7 @@
 /*
  * transupp.h
  *
- * Copyright (C) 1997, Thomas G. Lane.
+ * Copyright (C) 1997-2001, Thomas G. Lane.
  * This file is part of the Independent JPEG Group's software.
  * For conditions of distribution and use, see the accompanying README file.
  *
@@ -22,32 +22,6 @@
 #define TRANSFORMS_SUPPORTED 1		/* 0 disables transform code */
 #endif
 
-/* Short forms of external names for systems with brain-damaged linkers. */
-
-#ifdef NEED_SHORT_EXTERNAL_NAMES
-#define jtransform_request_workspace		jTrRequest
-#define jtransform_adjust_parameters		jTrAdjust
-#define jtransform_execute_transformation	jTrExec
-#define jcopy_markers_setup			jCMrkSetup
-#define jcopy_markers_execute			jCMrkExec
-#endif /* NEED_SHORT_EXTERNAL_NAMES */
-
-
-/*
- * Codes for supported types of image transformations.
- */
-
-typedef enum {
-	JXFORM_NONE,		/* no transformation */
-	JXFORM_FLIP_H,		/* horizontal flip */
-	JXFORM_FLIP_V,		/* vertical flip */
-	JXFORM_TRANSPOSE,	/* transpose across UL-to-LR axis */
-	JXFORM_TRANSVERSE,	/* transpose across UR-to-LL axis */
-	JXFORM_ROT_90,		/* 90-degree clockwise rotation */
-	JXFORM_ROT_180,		/* 180-degree rotation */
-	JXFORM_ROT_270		/* 270-degree clockwise (or 90 ccw) */
-} JXFORM_CODE;
-
 /*
  * Although rotating and flipping data expressed as DCT coefficients is not
  * hard, there is an asymmetry in the JPEG format specification for images
@@ -75,6 +49,19 @@
  * (For example, -rot 270 -trim trims only the bottom edge, but -rot 90 -trim
  * followed by -rot 180 -trim trims both edges.)
  *
+ * We also offer a lossless-crop option, which discards data outside a given
+ * image region but losslessly preserves what is inside.  Like the rotate and
+ * flip transforms, lossless crop is restricted by the JPEG format: the upper
+ * left corner of the selected region must fall on an iMCU boundary.  If this
+ * does not hold for the given crop parameters, we silently move the upper left
+ * corner up and/or left to make it so, simultaneously increasing the region
+ * dimensions to keep the lower right crop corner unchanged.  (Thus, the
+ * output image covers at least the requested region, but may cover more.)
+ *
+ * If both crop and a rotate/flip transform are requested, the crop is applied
+ * last --- that is, the crop region is specified in terms of the destination
+ * image.
+ *
  * We also offer a "force to grayscale" option, which simply discards the
  * chrominance channels of a YCbCr image.  This is lossless in the sense that
  * the luminance channel is preserved exactly.  It's not the same kind of
@@ -83,20 +70,96 @@
  * be aware of the option to know how many components to work on.
  */
 
+
+/* Short forms of external names for systems with brain-damaged linkers. */
+
+#ifdef NEED_SHORT_EXTERNAL_NAMES
+#define jtransform_parse_crop_spec	jTrParCrop
+#define jtransform_request_workspace	jTrRequest
+#define jtransform_adjust_parameters	jTrAdjust
+#define jtransform_execute_transform	jTrExec
+#define jtransform_perfect_transform	jTrPerfect
+#define jcopy_markers_setup		jCMrkSetup
+#define jcopy_markers_execute		jCMrkExec
+#endif /* NEED_SHORT_EXTERNAL_NAMES */
+
+
+/*
+ * Codes for supported types of image transformations.
+ */
+
+typedef enum {
+	JXFORM_NONE,		/* no transformation */
+	JXFORM_FLIP_H,		/* horizontal flip */
+	JXFORM_FLIP_V,		/* vertical flip */
+	JXFORM_TRANSPOSE,	/* transpose across UL-to-LR axis */
+	JXFORM_TRANSVERSE,	/* transpose across UR-to-LL axis */
+	JXFORM_ROT_90,		/* 90-degree clockwise rotation */
+	JXFORM_ROT_180,		/* 180-degree rotation */
+	JXFORM_ROT_270,		/* 270-degree clockwise (or 90 ccw) */
+        JXFORM_DROP             /* drop */
+} JXFORM_CODE;
+
+/*
+ * Codes for crop parameters, which can individually be unspecified,
+ * positive, or negative.  (Negative width or height makes no sense, though.)
+ */
+
+typedef enum {
+	JCROP_UNSET,
+	JCROP_POS,
+	JCROP_NEG
+} JCROP_CODE;
+
+/*
+ * Transform parameters struct.
+ * NB: application must not change any elements of this struct after
+ * calling jtransform_request_workspace.
+ */
+
 typedef struct {
   /* Options: set by caller */
   JXFORM_CODE transform;	/* image transform operator */
+  boolean perfect;		/* if TRUE, fail if partial MCUs are requested */
   boolean trim;			/* if TRUE, trim partial MCUs as needed */
   boolean force_grayscale;	/* if TRUE, convert color image to grayscale */
+  boolean crop;			/* if TRUE, crop source image */
+
+  /* Crop parameters: application need not set these unless crop is TRUE.
+   * These can be filled in by jtransform_parse_crop_spec().
+   */
+  JDIMENSION crop_width;	/* Width of selected region */
+  JCROP_CODE crop_width_set;
+  JDIMENSION crop_height;	/* Height of selected region */
+  JCROP_CODE crop_height_set;
+  JDIMENSION crop_xoffset;	/* X offset of selected region */
+  JCROP_CODE crop_xoffset_set;	/* (negative measures from right edge) */
+  JDIMENSION crop_yoffset;	/* Y offset of selected region */
+  JCROP_CODE crop_yoffset_set;	/* (negative measures from bottom edge) */
+
+  /* Drop parameters: set by caller for drop request */
+  j_decompress_ptr drop_ptr;
+  jvirt_barray_ptr * drop_coef_arrays;
 
   /* Internal workspace: caller should not touch these */
   int num_components;		/* # of components in workspace */
   jvirt_barray_ptr * workspace_coef_arrays; /* workspace for transformations */
+  JDIMENSION output_width;	/* cropped destination dimensions */
+  JDIMENSION output_height;
+  JDIMENSION x_crop_offset;	/* destination crop offsets measured in iMCUs */
+  JDIMENSION y_crop_offset;
+  JDIMENSION drop_width;       /* drop dimensions measured in iMCUs */
+  JDIMENSION drop_height;
+  int max_h_samp_factor;	/* destination iMCU size */
+  int max_v_samp_factor;
 } jpeg_transform_info;
 
 
 #if TRANSFORMS_SUPPORTED
 
+/* Parse a crop specification (written in X11 geometry style) */
+EXTERN(boolean) jtransform_parse_crop_spec
+	JPP((jpeg_transform_info *info, const char *spec));
 /* Request any required workspace */
 EXTERN(void) jtransform_request_workspace
 	JPP((j_decompress_ptr srcinfo, jpeg_transform_info *info));
@@ -106,10 +169,24 @@
 	     jvirt_barray_ptr *src_coef_arrays,
 	     jpeg_transform_info *info));
 /* Execute the actual transformation, if any */
-EXTERN(void) jtransform_execute_transformation
+EXTERN(void) jtransform_execute_transform
 	JPP((j_decompress_ptr srcinfo, j_compress_ptr dstinfo,
 	     jvirt_barray_ptr *src_coef_arrays,
 	     jpeg_transform_info *info));
+/* Determine whether lossless transformation is perfectly
+ * possible for a specified image and transformation.
+ */
+EXTERN(boolean) jtransform_perfect_transform
+	JPP((JDIMENSION image_width, JDIMENSION image_height,
+	     int MCU_width, int MCU_height,
+	     JXFORM_CODE transform));
+
+/* jtransform_execute_transform used to be called
+ * jtransform_execute_transformation, but some compilers complain about
+ * routine names that long.  This macro is here to avoid breaking any
+ * old source code that uses the original name...
+ */
+#define jtransform_execute_transformation	jtransform_execute_transform
 
 #endif /* TRANSFORMS_SUPPORTED */
 
@@ -121,7 +198,8 @@
 typedef enum {
 	JCOPYOPT_NONE,		/* copy no optional markers */
 	JCOPYOPT_COMMENTS,	/* copy only comment (COM) markers */
-	JCOPYOPT_ALL		/* copy all optional markers */
+	JCOPYOPT_ALL,		/* copy all optional markers */
+	JCOPYOPT_EXIF		/* copy Exif APP1 marker */
 } JCOPY_OPTION;
 
 #define JCOPYOPT_DEFAULT  JCOPYOPT_COMMENTS	/* recommended default */
