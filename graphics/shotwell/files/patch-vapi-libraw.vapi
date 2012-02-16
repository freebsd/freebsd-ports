--- vapi/libraw.vapi.orig	2012-02-15 17:16:39.000000000 -0800
+++ vapi/libraw.vapi	2012-02-15 17:18:38.000000000 -0800
@@ -14,17 +14,6 @@
 
 public unowned string versionNumber();
 
-[CCode (cname="enum libraw_Filtering", cprefix="LIBRAW_FILTERING_")]
-public enum Filtering {
-    DEFAULT,
-    NOZEROES,
-    NOBLACK,
-    NORAWCURVE,
-    NONE,
-    LIBRAWOWN,
-    AUTOMATIC
-}
-
 [SimpleType]
 [CCode (cname="libraw_imgother_t")]
 public struct ImageOther {
@@ -121,7 +110,6 @@
     public bool use_camera_wb;
     public bool use_camera_matrix;
     public int output_color;
-    public Filtering filtering_mode;
     public int output_bps;
     public bool output_tiff;
     public int user_flip;
@@ -132,6 +120,30 @@
     public bool no_auto_bright;
     public float auto_bright_thr;
     public int use_fuji_rotate;
+    public int green_matching;
+    
+    /* DCB parameters */
+    public int dcb_iterations;
+    public int dcb_enhance_fl;
+    public int fbdd_noiserd;
+    
+    /* VCD parameters */
+    public int eeci_refine;
+    public int es_med_passes;
+    /* AMaZE*/
+    public int ca_correc;
+    public float cared;
+    public float cablue;
+    public int cfaline;
+    public float linenoise;
+    public int cfa_clean;
+    public float lclean;
+    public float cclean;
+    public int cfa_green;
+    public float green_thresh;
+    public int exp_correc;
+    public float exp_shift;
+    public float exp_preser;
     
     public void set_chromatic_aberrations(double red_multiplier, double green_multiplier) {
         aber[0] = red_multiplier;
@@ -171,7 +183,6 @@
     [CCode (cname="libraw_init")]
     public Processor(Options flags = Options.NONE);
     
-    public void add_masked_borders_to_bitmap();
     public Result adjust_sizes_info_only();
     [CCode (cname="libraw_dcraw_document_mode_processing")]
     public Result document_mode_processing();
@@ -216,11 +227,11 @@
     OUT_OF_ORDER_CALL,
     NO_THUMBNAIL,
     UNSUPPORTED_THUMBNAIL,
-    CANNOT_ADDMASK,
     UNSUFFICIENT_MEMORY,
     DATA_ERROR,
     IO_ERROR,
-    CANCELLED_BY_CALLBACK;
+    CANCELLED_BY_CALLBACK,
+    BAD_CROP;
     
     [CCode (cname="LIBRAW_FATAL_ERROR")]
     public bool is_fatal_error();
