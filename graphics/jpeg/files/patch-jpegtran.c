--- jpegtran.c.orig	Wed Jul 23 22:37:26 1997
+++ jpegtran.c	Fri Jun  4 14:47:24 2004
@@ -1,7 +1,7 @@
 /*
  * jpegtran.c
  *
- * Copyright (C) 1995-1997, Thomas G. Lane.
+ * Copyright (C) 1995-2001, Thomas G. Lane.
  * This file is part of the Independent JPEG Group's software.
  * For conditions of distribution and use, see the accompanying README file.
  *
@@ -37,6 +37,7 @@
 
 static const char * progname;	/* program name for error messages */
 static char * outfilename;	/* for -outfile switch */
+static char * dropfilename;    /* for -drop switch */
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
@@ -64,12 +66,16 @@
 #endif
 #if TRANSFORMS_SUPPORTED
   fprintf(stderr, "Switches for modifying the image:\n");
+  fprintf(stderr, "  -crop WxH+X+Y  Crop to a rectangular subarea\n");
+  fprintf(stderr, "  -drop +X+Y filename          Drop another image\n");
   fprintf(stderr, "  -grayscale     Reduce to grayscale (omit color data)\n");
   fprintf(stderr, "  -flip [horizontal|vertical]  Mirror image (left-right or top-bottom)\n");
+  fprintf(stderr, "  -perfect       Fail if there is non-transformable edge blocks\n");
   fprintf(stderr, "  -rotate [90|180|270]         Rotate image (degrees clockwise)\n");
   fprintf(stderr, "  -transpose     Transpose image\n");
   fprintf(stderr, "  -transverse    Transverse transpose image\n");
-  fprintf(stderr, "  -trim          Drop non-transformable edge blocks\n");
+  fprintf(stderr, "  -trim          Drop non-transformable edge blocks or\n");
+  fprintf(stderr, "                 with -drop: Requantize drop file to source file\n");
 #endif /* TRANSFORMS_SUPPORTED */
   fprintf(stderr, "Switches for advanced users:\n");
   fprintf(stderr, "  -restart N     Set restart interval in rows, or in blocks with B\n");
@@ -109,6 +115,50 @@
 #endif
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
 
 LOCAL(int)
 parse_switches (j_compress_ptr cinfo, int argc, char **argv,
@@ -130,10 +180,13 @@
   /* Set up default JPEG parameters. */
   simple_progressive = FALSE;
   outfilename = NULL;
+  dropfilename = NULL;
   copyoption = JCOPYOPT_DEFAULT;
   transformoption.transform = JXFORM_NONE;
   transformoption.trim = FALSE;
+  transformoption.perfect = FALSE;
   transformoption.force_grayscale = FALSE;
+  transformoption.crop = FALSE;
   cinfo->err->trace_level = 0;
 
   /* Scan command line options, adjust parameters */
@@ -160,7 +213,7 @@
       exit(EXIT_FAILURE);
 #endif
 
-    } else if (keymatch(arg, "copy", 1)) {
+    } else if (keymatch(arg, "copy", 2)) {
       /* Select which extra markers to copy. */
       if (++argn >= argc)	/* advance to next argument */
 	usage();
@@ -170,9 +223,47 @@
 	copyoption = JCOPYOPT_COMMENTS;
       } else if (keymatch(argv[argn], "all", 1)) {
 	copyoption = JCOPYOPT_ALL;
+      } else if (keymatch(argv[argn], "exif", 1)) {
+	copyoption = JCOPYOPT_EXIF;
       } else
 	usage();
 
+    } else if (keymatch(arg, "crop", 2)) {
+      /* Perform lossless cropping. */
+#if TRANSFORMS_SUPPORTED
+      if (++argn >= argc)	/* advance to next argument */
+	usage();
+      if (transformoption.crop /* reject multiple crop/drop requests */ ||
+         ! jtransform_parse_crop_spec(&transformoption, argv[argn])) {
+	fprintf(stderr, "%s: bogus -crop argument '%s'\n",
+		progname, argv[argn]);
+	exit(EXIT_FAILURE);
+      }
+#else
+      select_transform(JXFORM_NONE);	/* force an error */
+#endif
+
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
+  
     } else if (keymatch(arg, "debug", 1) || keymatch(arg, "verbose", 1)) {
       /* Enable debug printouts. */
       /* On first -d, print version identification */
@@ -181,6 +272,7 @@
       if (! printed_version) {
 	fprintf(stderr, "Independent JPEG Group's JPEGTRAN, version %s\n%s\n",
 		JVERSION, JCOPYRIGHT);
+	fprintf(stderr, "EXIF support v 0.1 added 29-Sep-2003\n");
 	printed_version = TRUE;
       }
       cinfo->err->trace_level++;
@@ -233,7 +325,12 @@
 	usage();
       outfilename = argv[argn];	/* save it away for later use */
 
-    } else if (keymatch(arg, "progressive", 1)) {
+    } else if (keymatch(arg, "perfect", 2)) {
+      /* Fail if there is any partial edge MCUs that the transform can't
+       * handle. */
+      transformoption.perfect = TRUE;
+
+    } else if (keymatch(arg, "progressive", 2)) {
       /* Select simple progressive mode. */
 #ifdef C_PROGRESSIVE_SUPPORTED
       simple_progressive = TRUE;
@@ -334,16 +431,24 @@
 main (int argc, char **argv)
 {
   struct jpeg_decompress_struct srcinfo;
+  struct jpeg_error_mgr jsrcerr;
+#if TRANSFORMS_SUPPORTED
+  struct jpeg_decompress_struct dropinfo;
+  struct jpeg_error_mgr jdroperr;
+  FILE * drop_file;
+#endif
   struct jpeg_compress_struct dstinfo;
-  struct jpeg_error_mgr jsrcerr, jdsterr;
+  struct jpeg_error_mgr jdsterr;
 #ifdef PROGRESS_REPORT
   struct cdjpeg_progress_mgr progress;
 #endif
   jvirt_barray_ptr * src_coef_arrays;
   jvirt_barray_ptr * dst_coef_arrays;
   int file_index;
-  FILE * input_file;
-  FILE * output_file;
+  /* We assume all-in-memory processing and can therefore use only a
+   * single file pointer for sequential input and output operation. 
+   */
+  FILE * fp;
 
   /* On Mac, fetch a command line. */
 #ifdef USE_CCOMMAND
@@ -406,32 +511,36 @@
 
   /* Open the input file. */
   if (file_index < argc) {
-    if ((input_file = fopen(argv[file_index], READ_BINARY)) == NULL) {
-      fprintf(stderr, "%s: can't open %s\n", progname, argv[file_index]);
+    if ((fp = fopen(argv[file_index], READ_BINARY)) == NULL) {
+      fprintf(stderr, "%s: can't open %s for reading\n", progname, argv[file_index]);
       exit(EXIT_FAILURE);
     }
   } else {
     /* default input file is stdin */
-    input_file = read_stdin();
+    fp = read_stdin();
   }
-
-  /* Open the output file. */
-  if (outfilename != NULL) {
-    if ((output_file = fopen(outfilename, WRITE_BINARY)) == NULL) {
-      fprintf(stderr, "%s: can't open %s\n", progname, outfilename);
+#if TRANSFORMS_SUPPORTED
+  /* Open the drop file. */
+  if (dropfilename != NULL) {
+    if ((drop_file = fopen(dropfilename, READ_BINARY)) == NULL) {
+      fprintf(stderr, "%s: can't open %s for reading\n", progname, dropfilename);
       exit(EXIT_FAILURE);
     }
+    dropinfo.err = jpeg_std_error(&jdroperr);
+    jpeg_create_decompress(&dropinfo);
+    jpeg_stdio_src(&dropinfo, drop_file);
   } else {
-    /* default output file is stdout */
-    output_file = write_stdout();
+    drop_file = NULL;
   }
+#endif
+
 
 #ifdef PROGRESS_REPORT
   start_progress_monitor((j_common_ptr) &dstinfo, &progress);
 #endif
 
   /* Specify data source for decompression */
-  jpeg_stdio_src(&srcinfo, input_file);
+  jpeg_stdio_src(&srcinfo, fp);
 
   /* Enable saving of extra markers that we want to copy */
   jcopy_markers_setup(&srcinfo, copyoption);
@@ -439,19 +548,46 @@
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
 #if TRANSFORMS_SUPPORTED
+  /* Fails right away if -perfect is given and transformation is not perfect.
+   */
+  if (transformoption.perfect &&
+      !jtransform_perfect_transform(srcinfo.image_width, srcinfo.image_height,
+      srcinfo.max_h_samp_factor * DCTSIZE, srcinfo.max_v_samp_factor * DCTSIZE,
+      transformoption.transform)) {
+    fprintf(stderr, "%s: transformation is not perfect\n", progname);
+    exit(EXIT_FAILURE);
+  }
   jtransform_request_workspace(&srcinfo, &transformoption);
 #endif
 
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
 
+
   /* Adjust destination parameters if required by transform options;
    * also find out which set of coefficient arrays will hold the output.
    */
@@ -463,11 +599,36 @@
   dst_coef_arrays = src_coef_arrays;
 #endif
 
+  /* Close input file, if we opened it.
+   * Note: we assume that jpeg_read_coefficients consumed all input
+   * until JPEG_REACHED_EOI, and that jpeg_finish_decompress will
+   * only consume more while (! cinfo->inputctl->eoi_reached).
+   * We cannot call jpeg_finish_decompress here since we still need the
+   * virtual arrays allocated from the source object for processing.
+   */
+  if (fp != stdin)
+    fclose(fp);
+
+  /* Open the output file. */
+  if (outfilename != NULL) {
+    if ((fp = fopen(outfilename, WRITE_BINARY)) == NULL) {
+      fprintf(stderr, "%s: can't open %s for writing\n", progname, outfilename);
+      exit(EXIT_FAILURE);
+    }
+  } else {
+    /* default output file is stdout */
+    fp = write_stdout();
+  }
+
   /* Adjust default compression parameters by re-parsing the options */
+  /* Save value of copyoption */
   file_index = parse_switches(&dstinfo, argc, argv, 0, TRUE);
 
+  /* If we want EXIF, make sure we do not write incompatible markers */
+  handle_exif(&srcinfo,&dstinfo,&copyoption);
+                                                                                
   /* Specify data destination for compression */
-  jpeg_stdio_dest(&dstinfo, output_file);
+  jpeg_stdio_dest(&dstinfo, fp);
 
   /* Start compressor (note no image data is actually written here) */
   jpeg_write_coefficients(&dstinfo, dst_coef_arrays);
@@ -477,28 +638,41 @@
 
   /* Execute image transformation, if any */
 #if TRANSFORMS_SUPPORTED
-  jtransform_execute_transformation(&srcinfo, &dstinfo,
-				    src_coef_arrays,
-				    &transformoption);
+  jtransform_execute_transform(&srcinfo, &dstinfo,
+                              src_coef_arrays,
+                              &transformoption);  
 #endif
 
   /* Finish compression and release memory */
   jpeg_finish_compress(&dstinfo);
   jpeg_destroy_compress(&dstinfo);
+#if TRANSFORMS_SUPPORTED
+  if (dropfilename != NULL) {
+    (void) jpeg_finish_decompress(&dropinfo);
+    jpeg_destroy_decompress(&dropinfo);
+  }
+#endif
   (void) jpeg_finish_decompress(&srcinfo);
   jpeg_destroy_decompress(&srcinfo);
 
-  /* Close files, if we opened them */
-  if (input_file != stdin)
-    fclose(input_file);
-  if (output_file != stdout)
-    fclose(output_file);
+  /* Close output file, if we opened it */
+  if (fp != stdout)
+    fclose(fp);
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
