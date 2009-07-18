--- transupp.c.orig	2009-06-17 11:14:27.000000000 +0200
+++ transupp.c	2009-07-01 08:50:53.000000000 +0200
@@ -51,6 +51,13 @@
  * guarantee we can touch more than one row at a time.  So in that case,
  * we have to use a separate destination array.
  *
+ * If cropping or trimming is involved, the destination arrays may be smaller
+ * than the source arrays.  Note it is not possible to do horizontal flip
+ * in-place when a nonzero Y crop offset is specified, since we'd have to move
+ * data from one block row to another but the virtual array manager doesn't
+ * guarantee we can touch more than one row at a time.  So in that case,
+ * we have to use a separate destination array.
+ *
  * Some notes about the operating environment of the individual transform
  * routines:
  * 1. Both the source and destination virtual arrays are allocated from the
@@ -75,6 +82,269 @@
  */
 
 
+/* Drop code may be used with or without virtual memory adaptation code.
+ * This code has some dependencies on internal library behavior, so you
+ * may choose to disable it.  For example, it doesn't make a difference
+ * if you only use jmemnobs anyway.
+ */
+#ifndef DROP_REQUEST_FROM_SRC
+#define DROP_REQUEST_FROM_SRC 1		/* 0 disables adaptation */
+#endif
+
+
+#if DROP_REQUEST_FROM_SRC
+/* Force jpeg_read_coefficients to request
+ * the virtual coefficient arrays from
+ * the source decompression object.
+ */
+METHODDEF(jvirt_barray_ptr)
+drop_request_virt_barray (j_common_ptr cinfo, int pool_id, boolean pre_zero,
+			  JDIMENSION blocksperrow, JDIMENSION numrows,
+			  JDIMENSION maxaccess)
+{
+  j_decompress_ptr srcinfo = (j_decompress_ptr) cinfo->client_data;
+
+  return (*srcinfo->mem->request_virt_barray)
+	  ((j_common_ptr) srcinfo, pool_id, pre_zero,
+	   blocksperrow, numrows, maxaccess);
+}
+
+
+/* Force jpeg_read_coefficients to return
+ * after requesting and before accessing
+ * the virtual coefficient arrays.
+ */
+METHODDEF(int)
+drop_consume_input (j_decompress_ptr cinfo)
+{
+  return JPEG_SUSPENDED;
+}
+
+
+METHODDEF(void)
+drop_start_input_pass (j_decompress_ptr cinfo)
+{
+  cinfo->inputctl->consume_input = drop_consume_input;
+}
+
+
+LOCAL(void)
+drop_request_from_src (j_decompress_ptr dropinfo, j_decompress_ptr srcinfo)
+{
+  void *save_client_data;
+  JMETHOD(jvirt_barray_ptr, save_request_virt_barray,
+	  (j_common_ptr cinfo, int pool_id, boolean pre_zero,
+	   JDIMENSION blocksperrow, JDIMENSION numrows, JDIMENSION maxaccess));
+  JMETHOD(void, save_start_input_pass, (j_decompress_ptr cinfo));
+
+  /* Set custom method pointers, save original pointers */
+  save_client_data = dropinfo->client_data;
+  dropinfo->client_data = (void *) srcinfo;
+  save_request_virt_barray = dropinfo->mem->request_virt_barray;
+  dropinfo->mem->request_virt_barray = drop_request_virt_barray;
+  save_start_input_pass = dropinfo->inputctl->start_input_pass;
+  dropinfo->inputctl->start_input_pass = drop_start_input_pass;
+
+  /* Execute only initialization part.
+   * Requested coefficient arrays will be realized later by the srcinfo object.
+   * Next call to the same function will then do the actual data reading.
+   * NB: since we request the coefficient arrays from another object,
+   * the inherent realization call is effectively a no-op.
+   */
+  (void) jpeg_read_coefficients(dropinfo);
+
+  /* Reset method pointers */
+  dropinfo->client_data = save_client_data;
+  dropinfo->mem->request_virt_barray = save_request_virt_barray;
+  dropinfo->inputctl->start_input_pass = save_start_input_pass;
+  /* Do input initialization for first scan now,
+   * which also resets the consume_input method.
+   */
+  (*save_start_input_pass)(dropinfo);
+}
+#endif /* DROP_REQUEST_FROM_SRC */
+
+
+LOCAL(void)
+dequant_comp (j_decompress_ptr cinfo, jpeg_component_info *compptr,
+	      jvirt_barray_ptr coef_array, JQUANT_TBL *qtblptr1)
+{
+  JDIMENSION blk_x, blk_y;
+  int offset_y, k;
+  JQUANT_TBL *qtblptr;
+  JBLOCKARRAY buffer;
+  JBLOCKROW block;
+  JCOEFPTR ptr;
+
+  qtblptr = compptr->quant_table;
+  for (blk_y = 0; blk_y < compptr->height_in_blocks;
+       blk_y += compptr->v_samp_factor) {
+    buffer = (*cinfo->mem->access_virt_barray)
+      ((j_common_ptr) cinfo, coef_array, blk_y,
+       (JDIMENSION) compptr->v_samp_factor, TRUE);
+    for (offset_y = 0; offset_y < compptr->v_samp_factor; offset_y++) {
+      block = buffer[offset_y];
+      for (blk_x = 0; blk_x < compptr->width_in_blocks; blk_x++) {
+	ptr = block[blk_x];
+	for (k = 0; k < DCTSIZE2; k++)
+	  if (qtblptr->quantval[k] != qtblptr1->quantval[k])
+	    ptr[k] *= qtblptr->quantval[k] / qtblptr1->quantval[k];
+      }
+    }
+  }
+}
+
+
+LOCAL(void)
+requant_comp (j_decompress_ptr cinfo, jpeg_component_info *compptr,
+	      jvirt_barray_ptr coef_array, JQUANT_TBL *qtblptr1)
+{
+  JDIMENSION blk_x, blk_y;
+  int offset_y, k;
+  JQUANT_TBL *qtblptr;
+  JBLOCKARRAY buffer;
+  JBLOCKROW block;
+  JCOEFPTR ptr;
+  JCOEF temp, qval;
+
+  qtblptr = compptr->quant_table;
+  for (blk_y = 0; blk_y < compptr->height_in_blocks;
+       blk_y += compptr->v_samp_factor) {
+    buffer = (*cinfo->mem->access_virt_barray)
+      ((j_common_ptr) cinfo, coef_array, blk_y,
+       (JDIMENSION) compptr->v_samp_factor, TRUE);
+    for (offset_y = 0; offset_y < compptr->v_samp_factor; offset_y++) {
+      block = buffer[offset_y];
+      for (blk_x = 0; blk_x < compptr->width_in_blocks; blk_x++) {
+	ptr = block[blk_x];
+	for (k = 0; k < DCTSIZE2; k++) {
+	  temp = qtblptr->quantval[k];
+	  qval = qtblptr1->quantval[k];
+	  if (temp != qval) {
+	    temp *= ptr[k];
+	    /* The following quantization code is a copy from jcdctmgr.c */
+#ifdef FAST_DIVIDE
+#define DIVIDE_BY(a,b)	a /= b
+#else
+#define DIVIDE_BY(a,b)	if (a >= b) a /= b; else a = 0
+#endif
+	    if (temp < 0) {
+	      temp = -temp;
+	      temp += qval>>1;	/* for rounding */
+	      DIVIDE_BY(temp, qval);
+	      temp = -temp;
+	    } else {
+	      temp += qval>>1;	/* for rounding */
+	      DIVIDE_BY(temp, qval);
+	    }
+	    ptr[k] = temp;
+	  }
+	}
+      }
+    }
+  }
+}
+
+
+/* Calculate largest common denominator with Euklid's algorithm.
+ */
+LOCAL(JCOEF)
+largest_common_denominator(JCOEF a, JCOEF b)
+{
+  JCOEF c;
+
+  do {
+    c = a % b;
+    a = b;
+    b = c;
+  } while (c);
+
+  return a;
+}
+
+
+LOCAL(void)
+adjust_quant(j_decompress_ptr srcinfo, jvirt_barray_ptr *src_coef_arrays,
+	     j_decompress_ptr dropinfo, jvirt_barray_ptr *drop_coef_arrays,
+	     boolean trim, j_compress_ptr dstinfo)
+{
+  jpeg_component_info *compptr1, *compptr2;
+  JQUANT_TBL *qtblptr1, *qtblptr2, *qtblptr3;
+  int ci, k;
+
+  for (ci = 0; ci < dstinfo->num_components &&
+	       ci < dropinfo->num_components; ci++) {
+    compptr1 = srcinfo->comp_info + ci;
+    compptr2 = dropinfo->comp_info + ci;
+    qtblptr1 = compptr1->quant_table;
+    qtblptr2 = compptr2->quant_table;
+    for (k = 0; k < DCTSIZE2; k++) {
+      if (qtblptr1->quantval[k] != qtblptr2->quantval[k]) {
+	if (trim)
+	  requant_comp(dropinfo, compptr2, drop_coef_arrays[ci], qtblptr1);
+	else {
+	  qtblptr3 = dstinfo->quant_tbl_ptrs[compptr1->quant_tbl_no];
+	  for (k = 0; k < DCTSIZE2; k++)
+	    if (qtblptr1->quantval[k] != qtblptr2->quantval[k])
+	      qtblptr3->quantval[k] = largest_common_denominator
+		(qtblptr1->quantval[k], qtblptr2->quantval[k]);
+	  dequant_comp(srcinfo, compptr1, src_coef_arrays[ci], qtblptr3);
+	  dequant_comp(dropinfo, compptr2, drop_coef_arrays[ci], qtblptr3);
+	}
+	break;
+      }
+    }
+  }
+}
+
+
+LOCAL(void)
+do_drop (j_decompress_ptr srcinfo, j_compress_ptr dstinfo,
+	 JDIMENSION x_crop_offset, JDIMENSION y_crop_offset,
+	 jvirt_barray_ptr *src_coef_arrays,
+	 j_decompress_ptr dropinfo, jvirt_barray_ptr *drop_coef_arrays,
+	 JDIMENSION drop_width, JDIMENSION drop_height)
+/* Drop.  If the dropinfo component number is smaller than the destination's,
+ * we fill in the remaining components with zero.  This provides the feature
+ * of dropping grayscale into (arbitrarily sampled) color images.
+ */
+{
+  JDIMENSION comp_width, comp_height;
+  JDIMENSION blk_y, x_drop_blocks, y_drop_blocks;
+  int ci, offset_y;
+  JBLOCKARRAY src_buffer, dst_buffer;
+  jpeg_component_info *compptr;
+
+  for (ci = 0; ci < dstinfo->num_components; ci++) {
+    compptr = dstinfo->comp_info + ci;
+    comp_width = drop_width * compptr->h_samp_factor;
+    comp_height = drop_height * compptr->v_samp_factor;
+    x_drop_blocks = x_crop_offset * compptr->h_samp_factor;
+    y_drop_blocks = y_crop_offset * compptr->v_samp_factor;
+    for (blk_y = 0; blk_y < comp_height; blk_y += compptr->v_samp_factor) {
+      dst_buffer = (*srcinfo->mem->access_virt_barray)
+	((j_common_ptr) srcinfo, src_coef_arrays[ci], blk_y + y_drop_blocks,
+	 (JDIMENSION) compptr->v_samp_factor, TRUE);
+      if (ci < dropinfo->num_components) {
+	src_buffer = (*srcinfo->mem->access_virt_barray)
+	  ((j_common_ptr) srcinfo, drop_coef_arrays[ci], blk_y,
+	   (JDIMENSION) compptr->v_samp_factor, FALSE);
+	for (offset_y = 0; offset_y < compptr->v_samp_factor; offset_y++) {
+	  jcopy_block_row(src_buffer[offset_y],
+			  dst_buffer[offset_y] + x_drop_blocks,
+			  comp_width);
+	}
+      } else {
+	for (offset_y = 0; offset_y < compptr->v_samp_factor; offset_y++) {
+	  jzero_far(dst_buffer[offset_y] + x_drop_blocks,
+		    comp_width * SIZEOF(JBLOCK));
+	} 	
+      }
+    }
+  }
+}
+
+
 LOCAL(void)
 do_crop (j_decompress_ptr srcinfo, j_compress_ptr dstinfo,
 	 JDIMENSION x_crop_offset, JDIMENSION y_crop_offset,
@@ -82,16 +352,21 @@
 	 jvirt_barray_ptr *dst_coef_arrays)
 /* Crop.  This is only used when no rotate/flip is requested with the crop. */
 {
+  JDIMENSION MCU_cols, MCU_rows, comp_width, comp_height;
   JDIMENSION dst_blk_y, x_crop_blocks, y_crop_blocks;
   int ci, offset_y;
   JBLOCKARRAY src_buffer, dst_buffer;
   jpeg_component_info *compptr;
 
+  MCU_cols = srcinfo->image_width / (dstinfo->max_h_samp_factor * DCTSIZE);
+  MCU_rows = srcinfo->image_height / (dstinfo->max_v_samp_factor * DCTSIZE);
   /* We simply have to copy the right amount of data (the destination's
    * image size) starting at the given X and Y offsets in the source.
    */
   for (ci = 0; ci < dstinfo->num_components; ci++) {
     compptr = dstinfo->comp_info + ci;
+    comp_width = MCU_cols * compptr->h_samp_factor;
+    comp_height = MCU_rows * compptr->v_samp_factor;
     x_crop_blocks = x_crop_offset * compptr->h_samp_factor;
     y_crop_blocks = y_crop_offset * compptr->v_samp_factor;
     for (dst_blk_y = 0; dst_blk_y < compptr->height_in_blocks;
@@ -99,17 +374,49 @@
       dst_buffer = (*srcinfo->mem->access_virt_barray)
 	((j_common_ptr) srcinfo, dst_coef_arrays[ci], dst_blk_y,
 	 (JDIMENSION) compptr->v_samp_factor, TRUE);
+      if (dstinfo->image_height > srcinfo->image_height) {
+      if (dst_blk_y < y_crop_blocks ||
+          dst_blk_y >= comp_height + y_crop_blocks) {
+        for (offset_y = 0; offset_y < compptr->v_samp_factor; offset_y++) {
+          jzero_far(dst_buffer[offset_y],
+                    compptr->width_in_blocks * SIZEOF(JBLOCK));
+        }
+        continue;
+      }
+      src_buffer = (*srcinfo->mem->access_virt_barray)
+        ((j_common_ptr) srcinfo, src_coef_arrays[ci],
+         dst_blk_y - y_crop_blocks,
+         (JDIMENSION) compptr->v_samp_factor, FALSE);
+      } else {
       src_buffer = (*srcinfo->mem->access_virt_barray)
 	((j_common_ptr) srcinfo, src_coef_arrays[ci],
 	 dst_blk_y + y_crop_blocks,
 	 (JDIMENSION) compptr->v_samp_factor, FALSE);
+      }
       for (offset_y = 0; offset_y < compptr->v_samp_factor; offset_y++) {
+      if (dstinfo->image_width > srcinfo->image_width) {
+        if (x_crop_blocks > 0) {
+          jzero_far(dst_buffer[offset_y],
+                    x_crop_blocks * SIZEOF(JBLOCK));
+        }
+        jcopy_block_row(src_buffer[offset_y],
+                        dst_buffer[offset_y] + x_crop_blocks,
+                        comp_width);
+        if (compptr->width_in_blocks > comp_width + x_crop_blocks) {
+          jzero_far(dst_buffer[offset_y] +
+                      comp_width + x_crop_blocks,
+                    (compptr->width_in_blocks -
+                      comp_width - x_crop_blocks) * SIZEOF(JBLOCK));
+        }
+      } else {
+
 	jcopy_block_row(src_buffer[offset_y] + x_crop_blocks,
 			dst_buffer[offset_y],
 			compptr->width_in_blocks);
       }
     }
   }
+  }
 }
 
 
@@ -861,9 +1168,9 @@
   jvirt_barray_ptr *coef_arrays = NULL;
   boolean need_workspace, transpose_it;
   jpeg_component_info *compptr;
-  JDIMENSION xoffset, yoffset, width_in_iMCUs, height_in_iMCUs;
+  JDIMENSION xoffset, yoffset, dtemp, width_in_iMCUs, height_in_iMCUs;
   JDIMENSION width_in_blocks, height_in_blocks;
-  int ci, h_samp_factor, v_samp_factor;
+  int itemp, ci, h_samp_factor, v_samp_factor;
 
   /* Determine number of components in output image */
   if (info->force_grayscale &&
@@ -917,34 +1224,113 @@
     if (info->crop_xoffset_set == JCROP_UNSET)
       info->crop_xoffset = 0;	/* default to +0 */
     if (info->crop_yoffset_set == JCROP_UNSET)
-      info->crop_yoffset = 0;	/* default to +0 */
-    if (info->crop_xoffset >= info->output_width ||
-	info->crop_yoffset >= info->output_height)
+      info->crop_yoffset = 0; /* default to +0 */
+    if (info->crop_width_set == JCROP_UNSET) {
+      if (info->crop_xoffset >= info->output_width)
       ERREXIT(srcinfo, JERR_BAD_CROP_SPEC);
-    if (info->crop_width_set == JCROP_UNSET)
       info->crop_width = info->output_width - info->crop_xoffset;
-    if (info->crop_height_set == JCROP_UNSET)
+    } else {
+      /* Check for crop extension */
+      if (info->crop_width > info->output_width) {
+      /* Crop extension does not work when transforming! */
+      if (info->transform != JXFORM_NONE ||
+          info->crop_xoffset >= info->crop_width ||
+          info->crop_xoffset > info->crop_width - info->output_width)
+        ERREXIT(srcinfo, JERR_BAD_CROP_SPEC);
+      } else {
+      if (info->crop_xoffset >= info->output_width ||
+          info->crop_width <= 0 ||
+          info->crop_xoffset > info->output_width - info->crop_width)
+        ERREXIT(srcinfo, JERR_BAD_CROP_SPEC);
+      }
+    }
+    if (info->crop_height_set == JCROP_UNSET) {
+      if (info->crop_yoffset >= info->output_height)
+      ERREXIT(srcinfo, JERR_BAD_CROP_SPEC);
       info->crop_height = info->output_height - info->crop_yoffset;
-    /* Ensure parameters are valid */
-    if (info->crop_width <= 0 || info->crop_width > info->output_width ||
-	info->crop_height <= 0 || info->crop_height > info->output_height ||
-	info->crop_xoffset > info->output_width - info->crop_width ||
+    } else {
+      /* Check for crop extension */
+      if (info->crop_height > info->output_height) {
+      /* Crop extension does not work when transforming! */
+      if (info->transform != JXFORM_NONE ||
+          info->crop_yoffset >= info->crop_height ||
+          info->crop_yoffset > info->crop_height - info->output_height)
+        ERREXIT(srcinfo, JERR_BAD_CROP_SPEC);
+      } else {
+      if (info->crop_yoffset >= info->output_height ||
+          info->crop_height <= 0 ||
 	info->crop_yoffset > info->output_height - info->crop_height)
       ERREXIT(srcinfo, JERR_BAD_CROP_SPEC);
+      }
+    }
     /* Convert negative crop offsets into regular offsets */
-    if (info->crop_xoffset_set == JCROP_NEG)
+    if (info->crop_xoffset_set == JCROP_NEG) {
+      if (info->crop_width > info->output_width)
+      xoffset = info->crop_width - info->output_width - info->crop_xoffset;
+      else
       xoffset = info->output_width - info->crop_width - info->crop_xoffset;
-    else
+    } else
       xoffset = info->crop_xoffset;
-    if (info->crop_yoffset_set == JCROP_NEG)
+    if (info->crop_yoffset_set == JCROP_NEG) {
+      if (info->crop_height > info->output_height)
+      yoffset = info->crop_height - info->output_height - info->crop_yoffset;
+      else
       yoffset = info->output_height - info->crop_height - info->crop_yoffset;
-    else
+    } else
       yoffset = info->crop_yoffset;
     /* Now adjust so that upper left corner falls at an iMCU boundary */
+    if (info->transform == JXFORM_DROP) {
+      /* Ensure the effective drop region will not exceed the requested */
+      itemp = info->max_h_samp_factor * DCTSIZE;
+      dtemp = itemp - 1 - ((xoffset + itemp - 1) % itemp);
+      xoffset += dtemp;
+      if (info->crop_width > dtemp)
+      info->drop_width = (info->crop_width - dtemp) / itemp;
+      else
+      info->drop_width = 0;
+      itemp = info->max_v_samp_factor * DCTSIZE;
+      dtemp = itemp - 1 - ((yoffset + itemp - 1) % itemp);
+      yoffset += dtemp;
+      if (info->crop_height > dtemp)
+      info->drop_height = (info->crop_height - dtemp) / itemp;
+      else
+      info->drop_height = 0;
+      /* Check if sampling factors match for dropping */
+      if (info->drop_width != 0 && info->drop_height != 0)
+      for (ci = 0; ci < info->num_components &&
+                   ci < info->drop_ptr->num_components; ci++) {
+        if (info->drop_ptr->comp_info[ci].h_samp_factor *
+            srcinfo->max_h_samp_factor !=
+            srcinfo->comp_info[ci].h_samp_factor *
+            info->drop_ptr->max_h_samp_factor)
+          ERREXIT6(srcinfo, JERR_BAD_DROP_SAMPLING, ci,
+            info->drop_ptr->comp_info[ci].h_samp_factor,
+            info->drop_ptr->max_h_samp_factor,
+            srcinfo->comp_info[ci].h_samp_factor,
+            srcinfo->max_h_samp_factor, 'h');
+        if (info->drop_ptr->comp_info[ci].v_samp_factor *
+            srcinfo->max_v_samp_factor !=
+            srcinfo->comp_info[ci].v_samp_factor *
+            info->drop_ptr->max_v_samp_factor)
+          ERREXIT6(srcinfo, JERR_BAD_DROP_SAMPLING, ci,
+            info->drop_ptr->comp_info[ci].v_samp_factor,
+            info->drop_ptr->max_v_samp_factor,
+            srcinfo->comp_info[ci].v_samp_factor,
+            srcinfo->max_v_samp_factor, 'v');
+      }
+   } else {
+    /* Ensure the effective crop region will cover the requested */
+    if (info->crop_width > info->output_width)
+    info->output_width = info->crop_width;
+    else
     info->output_width =
       info->crop_width + (xoffset % (info->max_h_samp_factor * DCTSIZE));
+    if (info->crop_height > info->output_height)
+    info->output_height = info->crop_height;
+    else
     info->output_height =
       info->crop_height + (yoffset % (info->max_v_samp_factor * DCTSIZE));
+    }
     /* Save x/y offsets measured in iMCUs */
     info->x_crop_offset = xoffset / (info->max_h_samp_factor * DCTSIZE);
     info->y_crop_offset = yoffset / (info->max_v_samp_factor * DCTSIZE);
@@ -960,7 +1346,9 @@
   transpose_it = FALSE;
   switch (info->transform) {
   case JXFORM_NONE:
-    if (info->x_crop_offset != 0 || info->y_crop_offset != 0)
+    if (info->x_crop_offset != 0 || info->y_crop_offset != 0 ||
+      info->output_width > srcinfo->image_width ||
+      info->output_height > srcinfo->image_height)
       need_workspace = TRUE;
     /* No workspace needed if neither cropping nor transforming */
     break;
@@ -1014,6 +1402,11 @@
     need_workspace = TRUE;
     transpose_it = TRUE;
     break;
+  case JXFORM_DROP:
+#if DROP_REQUEST_FROM_SRC
+    drop_request_from_src(info->drop_ptr, srcinfo);
+#endif
+    break;
   }
 
   /* Allocate workspace if needed.
@@ -1309,6 +1702,11 @@
   case JXFORM_ROT_270:
     transpose_critical_parameters(dstinfo);
     break;
+  case JXFORM_DROP:
+    if (info->drop_width != 0 && info->drop_height != 0)
+      adjust_quant(srcinfo, src_coef_arrays,
+                 info->drop_ptr, info->drop_coef_arrays,
+                 info->trim, dstinfo);
   default:
     break;
   }
@@ -1363,7 +1761,9 @@
    */
   switch (info->transform) {
   case JXFORM_NONE:
-    if (info->x_crop_offset != 0 || info->y_crop_offset != 0)
+    if (info->x_crop_offset != 0 || info->y_crop_offset != 0 ||
+      info->output_width > srcinfo->image_width ||
+      info->output_height > srcinfo->image_height)
       do_crop(srcinfo, dstinfo, info->x_crop_offset, info->y_crop_offset,
 	      src_coef_arrays, dst_coef_arrays);
     break;
@@ -1399,6 +1799,12 @@
     do_rot_270(srcinfo, dstinfo, info->x_crop_offset, info->y_crop_offset,
 	       src_coef_arrays, dst_coef_arrays);
     break;
+  case JXFORM_DROP:
+    if (info->drop_width != 0 && info->drop_height != 0)
+      do_drop(srcinfo, dstinfo, info->x_crop_offset, info->y_crop_offset,
+            src_coef_arrays, info->drop_ptr, info->drop_coef_arrays,
+            info->drop_width, info->drop_height);
+    break;
   }
 }
 
