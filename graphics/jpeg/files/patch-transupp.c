--- transupp.c.exif	1997-08-10 02:15:26.000000000 +0200
+++ transupp.c	2003-09-29 22:28:42.000000000 +0200
@@ -717,6 +717,194 @@
 }
 
 
+/* Adjust Exif image parameters.
+ *
+ * We try to adjust the Tags ExifImageWidth, ExifImageHeight and
+ * ExifOrientation if possible. If the given new_* value is zero the
+ * corresponding tag is not adjusted.
+ */
+
+LOCAL(void)
+adjust_exif_parameters (JOCTET FAR * data, unsigned int length,
+			JDIMENSION new_width, JDIMENSION new_height,
+                        unsigned int new_orient)
+{
+  boolean is_motorola; /* Flag for byte order */
+  unsigned int number_of_tags, tagnum;
+  unsigned int firstoffset, offset, exifsuboffset;
+  JDIMENSION new_value;
+
+  if (length < 12) return; /* Length of an IFD entry */
+
+  /* Discover byte order */
+  if (GETJOCTET(data[0]) == 0x49 && GETJOCTET(data[1]) == 0x49)
+    is_motorola = FALSE;
+  else if (GETJOCTET(data[0]) == 0x4D && GETJOCTET(data[1]) == 0x4D)
+    is_motorola = TRUE;
+  else
+    return;
+
+  /* Check Tag Mark */
+  if (is_motorola) {
+    if (GETJOCTET(data[2]) != 0) return;
+    if (GETJOCTET(data[3]) != 0x2A) return;
+  } else {
+    if (GETJOCTET(data[3]) != 0) return;
+    if (GETJOCTET(data[2]) != 0x2A) return;
+  }
+
+  /* Get first IFD offset (offset to IFD0) */
+  if (is_motorola) {
+    if (GETJOCTET(data[4]) != 0) return;
+    if (GETJOCTET(data[5]) != 0) return;
+    firstoffset = GETJOCTET(data[6]);
+    firstoffset <<= 8;
+    firstoffset += GETJOCTET(data[7]);
+  } else {
+    if (GETJOCTET(data[7]) != 0) return;
+    if (GETJOCTET(data[6]) != 0) return;
+    firstoffset = GETJOCTET(data[5]);
+    firstoffset <<= 8;
+    firstoffset += GETJOCTET(data[4]);
+  }
+  if (firstoffset > length - 2) return; /* check end of data segment */
+
+  /* Get the number of directory entries contained in this IFD */
+  if (is_motorola) {
+    number_of_tags = GETJOCTET(data[firstoffset]);
+    number_of_tags <<= 8;
+    number_of_tags += GETJOCTET(data[firstoffset+1]);
+  } else {
+    number_of_tags = GETJOCTET(data[firstoffset+1]);
+    number_of_tags <<= 8;
+    number_of_tags += GETJOCTET(data[firstoffset]);
+  }
+  if (number_of_tags == 0) return;
+  firstoffset += 2;
+
+  /* Search for ExifSubIFD offset and ExifOrient Tag in IFD0 */
+  exifsuboffset = 0;
+  for (;;) {
+    if (firstoffset > length - 12) break; /* check end of data segment */
+    /* Get Tag number */
+    if (is_motorola) {
+      tagnum = GETJOCTET(data[firstoffset]);
+      tagnum <<= 8;
+      tagnum += GETJOCTET(data[firstoffset+1]);
+    } else {
+      tagnum = GETJOCTET(data[firstoffset+1]);
+      tagnum <<= 8;
+      tagnum += GETJOCTET(data[firstoffset]);
+    }
+    if (tagnum == 0x0112 && new_orient > 0) { /* found ExifOrientation */
+      if (is_motorola) {
+        data[firstoffset+2] = 0; /* Format = unsigned short (2 octets) */
+        data[firstoffset+3] = 3;
+        data[firstoffset+4] = 0; /* Number Of Components = 1 */
+        data[firstoffset+5] = 0;
+        data[firstoffset+6] = 0;
+        data[firstoffset+7] = 1;
+        data[firstoffset+8] = 0;
+        data[firstoffset+9] = (JOCTET)new_orient;
+        data[firstoffset+10] = 0;
+        data[firstoffset+11] = 0;
+      } else {
+        data[firstoffset+2] = 3; /* Format = unsigned short (2 octets) */
+        data[firstoffset+3] = 0;
+        data[firstoffset+4] = 1; /* Number Of Components = 1 */
+        data[firstoffset+5] = 0;
+        data[firstoffset+6] = 0;
+        data[firstoffset+7] = 0;
+        data[firstoffset+8] = (JOCTET)new_orient;
+        data[firstoffset+9] = 0;
+        data[firstoffset+10] = 0;
+        data[firstoffset+11] = 0;
+      }
+    } else if (tagnum == 0x8769) {
+      exifsuboffset = firstoffset; /* found ExifSubIFD offset Tag */
+    }
+    if (--number_of_tags == 0) break;
+    firstoffset += 12;
+  }
+  if (exifsuboffset == 0) return;
+
+  /* Get the ExifSubIFD offset */
+  if (is_motorola) {
+    if (GETJOCTET(data[exifsuboffset+8]) != 0) return;
+    if (GETJOCTET(data[exifsuboffset+9]) != 0) return;
+    offset = GETJOCTET(data[exifsuboffset+10]);
+    offset <<= 8;
+    offset += GETJOCTET(data[exifsuboffset+11]);
+  } else {
+    if (GETJOCTET(data[exifsuboffset+11]) != 0) return;
+    if (GETJOCTET(data[exifsuboffset+10]) != 0) return;
+    offset = GETJOCTET(data[exifsuboffset+9]);
+    offset <<= 8;
+    offset += GETJOCTET(data[exifsuboffset+8]);
+  }
+  if (offset > length - 2) return; /* check end of data segment */
+
+  /* Get the number of directory entries contained in this SubIFD */
+  if (is_motorola) {
+    number_of_tags = GETJOCTET(data[offset]);
+    number_of_tags <<= 8;
+    number_of_tags += GETJOCTET(data[offset+1]);
+  } else {
+    number_of_tags = GETJOCTET(data[offset+1]);
+    number_of_tags <<= 8;
+    number_of_tags += GETJOCTET(data[offset]);
+  }
+  if (number_of_tags < 2) return;
+  offset += 2;
+
+  /* Search for ExifImageWidth and ExifImageHeight Tags in this SubIFD */
+  do {
+    if (offset > length - 12) return; /* check end of data segment */
+    /* Get Tag number */
+    if (is_motorola) {
+      tagnum = GETJOCTET(data[offset]);
+      tagnum <<= 8;
+      tagnum += GETJOCTET(data[offset+1]);
+    } else {
+      tagnum = GETJOCTET(data[offset+1]);
+      tagnum <<= 8;
+      tagnum += GETJOCTET(data[offset]);
+    }
+    if ((tagnum == 0xA002 && new_width > 0) ||
+        (tagnum == 0xA003 && new_height > 0)) {
+      if (tagnum == 0xA002)
+	new_value = new_width; /* ExifImageWidth Tag */
+      else
+	new_value = new_height; /* ExifImageHeight Tag */
+      if (is_motorola) {
+	data[offset+2] = 0; /* Format = unsigned long (4 octets) */
+	data[offset+3] = 4;
+	data[offset+4] = 0; /* Number Of Components = 1 */
+	data[offset+5] = 0;
+	data[offset+6] = 0;
+	data[offset+7] = 1;
+	data[offset+8] = 0;
+	data[offset+9] = 0;
+	data[offset+10] = (JOCTET)((new_value >> 8) & 0xFF);
+	data[offset+11] = (JOCTET)(new_value & 0xFF);
+      } else {
+	data[offset+2] = 4; /* Format = unsigned long (4 octets) */
+	data[offset+3] = 0;
+	data[offset+4] = 1; /* Number Of Components = 1 */
+	data[offset+5] = 0;
+	data[offset+6] = 0;
+	data[offset+7] = 0;
+	data[offset+8] = (JOCTET)(new_value & 0xFF);
+	data[offset+9] = (JOCTET)((new_value >> 8) & 0xFF);
+	data[offset+10] = 0;
+	data[offset+11] = 0;
+      }
+    }
+    offset += 12;
+  } while (--number_of_tags);
+}
+
+
 /* Adjust output image parameters as needed.
  *
  * This must be called after jpeg_copy_critical_parameters()
@@ -734,6 +922,8 @@
 			      jvirt_barray_ptr *src_coef_arrays,
 			      jpeg_transform_info *info)
 {
+  jpeg_saved_marker_ptr cur_marker; /* ptr to walk the marker list */
+
   /* If force-to-grayscale is requested, adjust destination parameters */
   if (info->force_grayscale) {
     /* We use jpeg_set_colorspace to make sure subsidiary settings get fixed
@@ -799,6 +989,28 @@
     break;
   }
 
+  /* Adjust Exif properties. Exif requires its APP marker to be the first
+   * one, but we allow other locations for mixed JFIF/Exif files. */
+  cur_marker = srcinfo->marker_list;
+  while (cur_marker != NULL) {
+    if (cur_marker->marker == JPEG_APP0+1 &&
+        cur_marker->data_length >= 6 &&
+        GETJOCTET(cur_marker->data[0]) == 0x45 &&
+        GETJOCTET(cur_marker->data[1]) == 0x78 &&
+        GETJOCTET(cur_marker->data[2]) == 0x69 &&
+        GETJOCTET(cur_marker->data[3]) == 0x66 &&
+        GETJOCTET(cur_marker->data[4]) == 0 &&
+        GETJOCTET(cur_marker->data[5]) == 0) {
+      /* Adjust Exif image parameters */
+      if (info->transform != JXFORM_NONE)
+        /* Align data segment to start of TIFF structure for parsing */
+        adjust_exif_parameters(cur_marker->data + 6,
+                               cur_marker->data_length - 6,
+                               dstinfo->image_width, dstinfo->image_height, 1);
+    }
+    cur_marker = cur_marker->next;
+  }
+
   /* Return the appropriate output data set */
   if (info->workspace_coef_arrays != NULL)
     return info->workspace_coef_arrays;
@@ -854,6 +1066,8 @@
 
 
 /* Setup decompression object to save desired markers in memory.
+ * Unless JCOPYOPT_NONE is given, the COM and potential EXIF markers (APP1)
+ * are always saved.
  * This must be called before jpeg_read_header() to have the desired effect.
  */
 
@@ -871,6 +1085,8 @@
   if (option == JCOPYOPT_ALL) {
     for (m = 0; m < 16; m++)
       jpeg_save_markers(srcinfo, JPEG_APP0 + m, 0xFFFF);
+  } else if (option != JCOPYOPT_NONE) {
+    jpeg_save_markers(srcinfo, JPEG_APP0 + 1, 0xFFFF);
   }
 #endif /* SAVE_MARKERS_SUPPORTED */
 }
@@ -888,12 +1104,27 @@
 {
   jpeg_saved_marker_ptr marker;
 
-  /* In the current implementation, we don't actually need to examine the
-   * option flag here; we just copy everything that got saved.
-   * But to avoid confusion, we do not output JFIF and Adobe APP14 markers
+  /* NOTE: to avoid confusion, we do not output JFIF and Adobe APP14 markers
    * if the encoder library already wrote one.
    */
+  if (option == JCOPYOPT_NONE) return;
   for (marker = srcinfo->marker_list; marker != NULL; marker = marker->next) {
+    if (option == JCOPYOPT_COMMENTS &&
+        marker->marker != JPEG_COM) {
+      continue;         /* only COM accpeted if JCOPYOPT_COMMENTS */
+    }
+    if (option == JCOPYOPT_EXIF &&
+        marker->marker != JPEG_COM &&
+        !(marker->marker == JPEG_APP0+1 &&
+          marker->data_length >= 6 &&
+          GETJOCTET(marker->data[0]) == 0x45 &&
+          GETJOCTET(marker->data[1]) == 0x78 &&
+          GETJOCTET(marker->data[2]) == 0x69 &&
+          GETJOCTET(marker->data[3]) == 0x66 &&
+          GETJOCTET(marker->data[4]) == 0 &&
+          GETJOCTET(marker->data[5]) == 0)) {
+      continue;         /* only COM and APP1-EXIF if JCOPYOPT_EXIF */
+    }
     if (dstinfo->write_JFIF_header &&
 	marker->marker == JPEG_APP0 &&
 	marker->data_length >= 5 &&
