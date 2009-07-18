--- jpegtran.c.orig	2003-09-22 00:00:52.000000000 +0200
+++ jpegtran.c	2009-06-30 13:41:20.000000000 +0200
@@ -37,6 +37,7 @@
 
 static const char * progname;	/* program name for error messages */
 static char * outfilename;	/* for -outfile switch */
+static char * dropfilename;	/* for -drop switch */
 static JCOPY_OPTION copyoption;	/* -copy switch */
 static jpeg_transform_info transformoption; /* image transformation options */
 
@@ -56,6 +57,7 @@
   fprintf(stderr, "  -copy none     Copy no extra markers from source file\n");
   fprintf(stderr, "  -copy comments Copy only comment markers (default)\n");
   fprintf(stderr, "  -copy all      Copy all extra markers\n");
+  fprintf(stderr, "  -copy exif     Copy EXIF marker and omit JFIF if EXIF\n");
 #ifdef ENTROPY_OPT_SUPPORTED
   fprintf(stderr, "  -optimize      Optimize Huffman table (smaller file, but slow compression)\n");
 #endif
@@ -65,13 +67,15 @@
 #if TRANSFORMS_SUPPORTED
   fprintf(stderr, "Switches for modifying the image:\n");
   fprintf(stderr, "  -crop WxH+X+Y  Crop to a rectangular subarea\n");
+  fprintf(stderr, "  -drop +X+Y filename          Drop another image\n");
   fprintf(stderr, "  -grayscale     Reduce to grayscale (omit color data)\n");
   fprintf(stderr, "  -flip [horizontal|vertical]  Mirror image (left-right or top-bottom)\n");
   fprintf(stderr, "  -perfect       Fail if there is non-transformable edge blocks\n");
   fprintf(stderr, "  -rotate [90|180|270]         Rotate image (degrees clockwise)\n");
   fprintf(stderr, "  -transpose     Transpose image\n");
   fprintf(stderr, "  -transverse    Transverse transpose image\n");
-  fprintf(stderr, "  -trim          Drop non-transformable edge blocks\n");
+  fprintf(stderr, "  -trim          Drop non-transformable edge blocks or\n");
+  fprintf(stderr, "                 with -drop: Requantize drop file to source file\n");
 #endif /* TRANSFORMS_SUPPORTED */
   fprintf(stderr, "Switches for advanced users:\n");
   fprintf(stderr, "  -restart N     Set restart interval in rows, or in blocks with B\n");
@@ -112,6 +116,52 @@
 }
 
 
+LOCAL(void)
+handle_exif (j_decompress_ptr srcinfo, j_compress_ptr dstinfo,
+             JCOPY_OPTION *copyoption)
+/* Adjust the marker writing options to create an EXIF file, instead of JFIF,
+ * if so requested or an EXIF file is detected as input. Must be called after
+ * jpeg_copy_critical_parameters() as that sets the defaults. */
+{
+  jpeg_saved_marker_ptr cur_marker, prev_marker;
+
+  /* Look for an exif marker */
+  prev_marker = NULL;
+  cur_marker = srcinfo->marker_list;
+  while (cur_marker != NULL) {
+    if (cur_marker->marker == JPEG_APP0+1 &&
+        cur_marker->data_length >= 6 &&
+        GETJOCTET(cur_marker->data[0]) == 0x45 &&
+        GETJOCTET(cur_marker->data[1]) == 0x78 &&
+        GETJOCTET(cur_marker->data[2]) == 0x69 &&
+        GETJOCTET(cur_marker->data[3]) == 0x66 &&
+        GETJOCTET(cur_marker->data[4]) == 0 &&
+        GETJOCTET(cur_marker->data[5]) == 0)
+      break; /* found an EXIF marker */
+    prev_marker = cur_marker;
+    cur_marker = cur_marker->next;
+  }
+  /* If we've found an EXIF marker but not JFIF this is an EXIF file. Unless
+   * explicitely requested, make sure we keep the EXIF marker and do not
+   * emit a JFIF marker (which would come before). EXIF requires that the
+   * first marker be EXIF. */
+  if (cur_marker != NULL &&
+      ((*copyoption != JCOPYOPT_NONE && !srcinfo->saw_JFIF_marker) ||
+       (*copyoption == JCOPYOPT_EXIF))) {
+    dstinfo->write_JFIF_header = FALSE;
+    if (*copyoption == JCOPYOPT_COMMENTS)
+      *copyoption = JCOPYOPT_EXIF;
+  }
+  /* If making an EXIF file, make sure that EXIF is first marker */
+  if (cur_marker != NULL && prev_marker != NULL &&
+      *copyoption == JCOPYOPT_EXIF) {
+    prev_marker->next = cur_marker->next;
+    cur_marker->next = srcinfo->marker_list;
+    srcinfo->marker_list = cur_marker;
+  }
+}
+
+
 LOCAL(int)
 parse_switches (j_compress_ptr cinfo, int argc, char **argv,
 		int last_file_arg_seen, boolean for_real)
@@ -132,6 +182,7 @@
   /* Set up default JPEG parameters. */
   simple_progressive = FALSE;
   outfilename = NULL;
+  dropfilename = NULL;
   copyoption = JCOPYOPT_DEFAULT;
   transformoption.transform = JXFORM_NONE;
   transformoption.trim = FALSE;
@@ -174,6 +225,8 @@
 	copyoption = JCOPYOPT_COMMENTS;
       } else if (keymatch(argv[argn], "all", 1)) {
 	copyoption = JCOPYOPT_ALL;
+      } else if (keymatch(argv[argn], "exif", 1)) {
+        copyoption = JCOPYOPT_EXIF;
       } else
 	usage();
 
@@ -191,6 +244,26 @@
       select_transform(JXFORM_NONE);	/* force an error */
 #endif
 
+    } else if (keymatch(arg, "drop", 2)) {
+#if TRANSFORMS_SUPPORTED
+      if (++argn >= argc)      /* advance to next argument */
+       usage();
+      if (transformoption.crop /* reject multiple crop/drop requests */ ||
+         ! jtransform_parse_crop_spec(&transformoption, argv[argn]) ||
+         transformoption.crop_width_set != JCROP_UNSET ||
+         transformoption.crop_height_set != JCROP_UNSET) {
+       fprintf(stderr, "%s: bogus -drop argument '%s'\n",
+               progname, argv[argn]);
+       exit(EXIT_FAILURE);
+      }
+      if (++argn >= argc)      /* advance to next argument */
+       usage();
+      dropfilename = argv[argn];
+      select_transform(JXFORM_DROP);
+#else
+      select_transform(JXFORM_NONE);   /* force an error */
+#endif
+
     } else if (keymatch(arg, "debug", 1) || keymatch(arg, "verbose", 1)) {
       /* Enable debug printouts. */
       /* On first -d, print version identification */
@@ -199,6 +272,7 @@
       if (! printed_version) {
 	fprintf(stderr, "Independent JPEG Group's JPEGTRAN, version %s\n%s\n",
 		JVERSION, JCOPYRIGHT);
+        fprintf(stderr, "EXIF support v 0.1 added 29-Sep-2003\n");
 	printed_version = TRUE;
       }
       cinfo->err->trace_level++;
@@ -359,6 +433,11 @@
   struct jpeg_decompress_struct srcinfo;
   struct jpeg_compress_struct dstinfo;
   struct jpeg_error_mgr jsrcerr, jdsterr;
+#if TRANSFORMS_SUPPORTED
+  struct jpeg_decompress_struct dropinfo;
+  struct jpeg_error_mgr jdroperr;
+  FILE * drop_file;
+#endif
 #ifdef PROGRESS_REPORT
   struct cdjpeg_progress_mgr progress;
 #endif
@@ -440,6 +519,21 @@
     fp = read_stdin();
   }
 
+#if TRANSFORMS_SUPPORTED
+  /* Open the drop file. */
+  if (dropfilename != NULL) {
+    if ((drop_file = fopen(dropfilename, READ_BINARY)) == NULL) {
+      fprintf(stderr, "%s: can't open %s for reading\n", progname, dropfilename);
+      exit(EXIT_FAILURE);
+    }
+    dropinfo.err = jpeg_std_error(&jdroperr);
+    jpeg_create_decompress(&dropinfo);
+    jpeg_stdio_src(&dropinfo, drop_file);
+  } else {
+    drop_file = NULL;
+  }
+#endif
+
 #ifdef PROGRESS_REPORT
   start_progress_monitor((j_common_ptr) &dstinfo, &progress);
 #endif
@@ -453,6 +547,17 @@
   /* Read file header */
   (void) jpeg_read_header(&srcinfo, TRUE);
 
+#if TRANSFORMS_SUPPORTED
+  if (dropfilename != NULL) {
+    (void) jpeg_read_header(&dropinfo, TRUE);
+    transformoption.crop_width = dropinfo.image_width;
+    transformoption.crop_width_set = JCROP_POS;
+    transformoption.crop_height = dropinfo.image_height;
+    transformoption.crop_height_set = JCROP_POS;
+    transformoption.drop_ptr = &dropinfo;
+  }
+#endif
+
   /* Any space needed by a transform option must be requested before
    * jpeg_read_coefficients so that memory allocation will be done right.
    */
@@ -472,6 +577,12 @@
   /* Read source file as DCT coefficients */
   src_coef_arrays = jpeg_read_coefficients(&srcinfo);
 
+#if TRANSFORMS_SUPPORTED
+  if (dropfilename != NULL) {
+    transformoption.drop_coef_arrays = jpeg_read_coefficients(&dropinfo);
+  }
+#endif
+
   /* Initialize destination compression parameters from source values */
   jpeg_copy_critical_parameters(&srcinfo, &dstinfo);
 
@@ -510,6 +621,9 @@
   /* Adjust default compression parameters by re-parsing the options */
   file_index = parse_switches(&dstinfo, argc, argv, 0, TRUE);
 
+  /* If we want EXIF, make sure we do not write incompatible markers */
+  handle_exif(&srcinfo,&dstinfo,&copyoption);
+                                                                                
   /* Specify data destination for compression */
   jpeg_stdio_dest(&dstinfo, fp);
 
@@ -531,16 +645,30 @@
   jpeg_destroy_compress(&dstinfo);
   (void) jpeg_finish_decompress(&srcinfo);
   jpeg_destroy_decompress(&srcinfo);
-
+#if TRANSFORMS_SUPPORTED
+  if (dropfilename != NULL) {
+    (void) jpeg_finish_decompress(&dropinfo);
+    jpeg_destroy_decompress(&dropinfo);
+  }
+#endif
   /* Close output file, if we opened it */
   if (fp != stdout)
     fclose(fp);
+#if TRANSFORMS_SUPPORTED
+  if (drop_file != NULL)
+    fclose(drop_file);
+#endif
 
 #ifdef PROGRESS_REPORT
   end_progress_monitor((j_common_ptr) &dstinfo);
 #endif
 
   /* All done. */
+#if TRANSFORMS_SUPPORTED
+  if (dropfilename != NULL)
+    exit(jsrcerr.num_warnings + jdroperr.num_warnings + jdsterr.num_warnings ?
+        EXIT_WARNING : EXIT_SUCCESS);
+#endif
   exit(jsrcerr.num_warnings + jdsterr.num_warnings ?EXIT_WARNING:EXIT_SUCCESS);
   return 0;			/* suppress no-return-value warnings */
 }
