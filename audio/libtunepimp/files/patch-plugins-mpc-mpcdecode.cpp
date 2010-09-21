--- plugins/mpc/mpcdecode.cpp.orig	2006-11-18 11:51:08.000000000 +0100
+++ plugins/mpc/mpcdecode.cpp	2010-09-11 11:46:56.335821789 +0200
@@ -29,8 +29,9 @@
 #include <assert.h>
 #include <time.h>
 #include "fileio.h"
+#include "config.h"
 
-#include <mpcdec/mpcdec.h> 
+#include <mpc/mpcdec.h>
 
 extern char *mpcErrorString;
 
@@ -40,35 +41,35 @@
 } reader_data;
 
 static mpc_int32_t
-read_impl(void *data, void *ptr, mpc_int32_t size)
+read_impl(mpc_reader *data, void *ptr, mpc_int32_t size)
 {
-    reader_data *d = (reader_data *) data;
+    reader_data *d = (reader_data *) data->data;
     return tread(ptr, 1, size, d->file);
 }
 
 static mpc_bool_t
-seek_impl(void *data, mpc_int32_t offset)
+seek_impl(mpc_reader *data, mpc_int32_t offset)
 {
-    reader_data *d = (reader_data *) data;
+    reader_data *d = (reader_data *) data->data;
     return !tseek(d->file, offset, SEEK_SET);
 }
 
 static mpc_int32_t
-tell_impl(void *data)
+tell_impl(mpc_reader *data)
 {
-    reader_data *d = (reader_data *) data;
+    reader_data *d = (reader_data *) data->data;
     return ttell(d->file);
 }
 
 static mpc_int32_t
-get_size_impl(void *data)
+get_size_impl(mpc_reader *data)
 {
-    reader_data *d = (reader_data *) data;
+    reader_data *d = (reader_data *) data->data;
     return d->size;
 }
 
 static mpc_bool_t
-canseek_impl(void *data)
+canseek_impl(mpc_reader *data)
 {
     return true;
 } 
@@ -76,7 +77,7 @@
 typedef struct mpc_decode_struct_t {
     TFILE *file;
     reader_data rdata;
-    mpc_decoder decoder;
+    mpc_demux *decoder;
     mpc_reader reader;
     mpc_streaminfo info;
     MPC_SAMPLE_FORMAT buffer[MPC_DECODER_BUFFER_LENGTH];
@@ -114,27 +115,21 @@
     ds->reader.canseek = canseek_impl;
     ds->reader.data = &ds->rdata;     
     
-    /* read file's streaminfo data */
-    mpc_streaminfo_init(&ds->info);
-    if (mpc_streaminfo_read(&ds->info, &ds->reader) != ERROR_CODE_OK) {
-        mpcErrorString = "Not a valid Musepack file.";
-        goto error;
-    }     
-    
-    /* instantiate a decoder with our file reader */
-    mpc_decoder_setup(&ds->decoder, &ds->reader);
-    if (!mpc_decoder_initialize(&ds->decoder, &ds->info)) {
-        mpcErrorString = "Error initializing decoder.";
-        goto error;
-    }     
-    
+    ds->decoder = mpc_demux_init(&ds->reader);
+    if (!ds->decoder) {
+	mpcErrorString = "Error initializing decoder.";
+	goto error;
+    }
+
+    mpc_demux_get_info(ds->decoder, &ds->info);
+
     return ds;
     
 error:
-    if (ds)
-        delete ds;
-    
-    return NULL;
+    if (ds) {
+      mpc_demux_exit(ds->decoder);
+      delete ds;
+    }
 }
 
 extern "C" int
@@ -144,7 +139,8 @@
         return 0;
         
     if (duration)
-        *duration = (ds->info.pcm_samples * 1000) / ds->info.sample_freq;
+        *duration = ((ds->info.samples - ds->info.beg_silence) * 1000)
+	  / ds->info.sample_freq;
     if (samplesPerSecond)
         *samplesPerSecond = ds->info.sample_freq;
     if (bitsPerSample)
@@ -173,6 +169,8 @@
         return -1;
         
     unsigned status, maxSamples = maxBytes / 2 / ds->info.channels, samples, offset;
+    mpc_frame_info frame;
+    mpc_status err;
     
     if (ds->samples > 0) {
         samples = ds->samples;
@@ -182,15 +180,18 @@
         goto convert;
     }
     
-    status = mpc_decoder_decode(&ds->decoder, ds->buffer, 0, 0);
-    
-    if (status == (unsigned)(-1)) { //decode error
-        mpcErrorString = "Error decoding file.";
-        return -1;
+    frame.buffer = ds->buffer;
+    err = mpc_demux_decode(ds->decoder, &frame);
+
+    if (err != MPC_STATUS_OK) { //decode error
+	mpcErrorString = "Error decoding file.";
+	return -1;
     }
-    else if (status == 0) { //EOF
-        return 0;
+    else if (frame.bits == -1) { //EOF
+	return 0;
     }
+
+    status = frame.samples;
     
     if (status > maxSamples) {
         ds->samples = status - maxSamples;
@@ -230,8 +231,10 @@
 extern "C" void
 mpcDecodeEnd(mpc_decode_struct_t *ds)
 {
-    if (ds) 
-        delete ds;
+  if (ds) {
+      mpc_demux_exit(ds->decoder);
+      delete ds;
+  }
 }
 
 
