--- jpegtran.c.exif	1997-07-24 04:37:26.000000000 +0200
+++ jpegtran.c	2003-09-29 22:31:22.000000000 +0200
@@ -56,6 +56,7 @@
   fprintf(stderr, "  -copy none     Copy no extra markers from source file\n");
   fprintf(stderr, "  -copy comments Copy only comment markers (default)\n");
   fprintf(stderr, "  -copy all      Copy all extra markers\n");
+  fprintf(stderr, "  -copy exif     Copy EXIF marker and omit JFIF if EXIF\n");
 #ifdef ENTROPY_OPT_SUPPORTED
   fprintf(stderr, "  -optimize      Optimize Huffman table (smaller file, but slow compression)\n");
 #endif
@@ -109,6 +110,50 @@
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
@@ -170,6 +215,8 @@
 	copyoption = JCOPYOPT_COMMENTS;
       } else if (keymatch(argv[argn], "all", 1)) {
 	copyoption = JCOPYOPT_ALL;
+      } else if (keymatch(argv[argn], "exif", 1)) {
+	copyoption = JCOPYOPT_EXIF;
       } else
 	usage();
 
@@ -181,6 +228,7 @@
       if (! printed_version) {
 	fprintf(stderr, "Independent JPEG Group's JPEGTRAN, version %s\n%s\n",
 		JVERSION, JCOPYRIGHT);
+	fprintf(stderr, "EXIF support v 0.1 added 29-Sep-2003\n");
 	printed_version = TRUE;
       }
       cinfo->err->trace_level++;
@@ -452,6 +500,7 @@
   /* Initialize destination compression parameters from source values */
   jpeg_copy_critical_parameters(&srcinfo, &dstinfo);
 
+
   /* Adjust destination parameters if required by transform options;
    * also find out which set of coefficient arrays will hold the output.
    */
@@ -464,8 +513,12 @@
 #endif
 
   /* Adjust default compression parameters by re-parsing the options */
+  /* Save value of copyoption */
   file_index = parse_switches(&dstinfo, argc, argv, 0, TRUE);
 
+  /* If we want EXIF, make sure we do not write incompatible markers */
+  handle_exif(&srcinfo,&dstinfo,&copyoption);
+                                                                                
   /* Specify data destination for compression */
   jpeg_stdio_dest(&dstinfo, output_file);
 
