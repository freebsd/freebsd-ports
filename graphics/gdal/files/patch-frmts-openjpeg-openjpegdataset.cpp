--- frmts/openjpeg/openjpegdataset.cpp.orig	2014-04-17 04:04:48.000000000 +0800
+++ frmts/openjpeg/openjpegdataset.cpp	2014-08-22 15:05:34.093308400 +0800
@@ -29,8 +29,12 @@
 
 /* This file is to be used with openjpeg 2.0 */
 
+#if defined(OPENJPEG_VERSION) && OPENJPEG_VERSION >= 20100
+#include <openjpeg-2.1/openjpeg.h>
+#else
 #include <stdio.h> /* openjpeg.h needs FILE* */
 #include <openjpeg-2.0/openjpeg.h>
+#endif
 #include <vector>
 
 #include "gdaljp2abstractdataset.h"
@@ -612,7 +616,11 @@
     opj_stream_set_read_function(pStream, JP2OpenJPEGDataset_Read);
     opj_stream_set_seek_function(pStream, JP2OpenJPEGDataset_Seek);
     opj_stream_set_skip_function(pStream, JP2OpenJPEGDataset_Skip);
+#if defined(OPENJPEG_VERSION) && OPENJPEG_VERSION >= 20100
+    opj_stream_set_user_data(pStream, fp, NULL);
+#else
     opj_stream_set_user_data(pStream, fp);
+#endif
 
     if(!opj_read_header(pStream,pCodec,&psImage))
     {
@@ -948,7 +956,11 @@
     opj_stream_set_read_function(pStream, JP2OpenJPEGDataset_Read);
     opj_stream_set_seek_function(pStream, JP2OpenJPEGDataset_Seek);
     opj_stream_set_skip_function(pStream, JP2OpenJPEGDataset_Skip);
+#if defined(OPENJPEG_VERSION) && OPENJPEG_VERSION >= 20100
+    opj_stream_set_user_data(pStream, fp, NULL);
+#else
     opj_stream_set_user_data(pStream, fp);
+#endif
 
     opj_image_t * psImage = NULL;
     OPJ_INT32  nX0,nY0;
@@ -1496,7 +1508,11 @@
     opj_stream_set_write_function(pStream, JP2OpenJPEGDataset_Write);
     opj_stream_set_seek_function(pStream, JP2OpenJPEGDataset_Seek);
     opj_stream_set_skip_function(pStream, JP2OpenJPEGDataset_Skip);
+#if defined(OPENJPEG_VERSION) && OPENJPEG_VERSION >= 20100
+    opj_stream_set_user_data(pStream, fp, NULL);
+#else
     opj_stream_set_user_data(pStream, fp);
+#endif
 
     if (!opj_start_compress(pCodec,psImage,pStream))
     {
