--- Bundles/FLAC/FLAC.m.orig	2006-03-21 22:39:13.000000000 +0100
+++ Bundles/FLAC/FLAC.m	2008-03-27 17:23:35.000000000 +0100
@@ -39,7 +39,7 @@
 #define LOCALIZED(X) _b ([FLAC class], X)
 
 static FLAC__StreamDecoderWriteStatus
-writeCallback (const FLAC__FileDecoder *fileDecoder, const FLAC__Frame *frame,
+writeCallback (const FLAC__StreamDecoder *fileDecoder, const FLAC__Frame *frame,
                const FLAC__int32 * const buffer[], void *clientData)
 {
   CFLAC *cStream;
@@ -70,7 +70,7 @@ writeCallback (const FLAC__FileDecoder *
 }
 
 static void
-metadataCallback (const FLAC__FileDecoder *fileDecoder,
+metadataCallback (const FLAC__StreamDecoder *fileDecoder,
                   const FLAC__StreamMetadata *metadata,
                   void *clientData)
 {
@@ -88,7 +88,7 @@ metadataCallback (const FLAC__FileDecode
 }
 
 static void
-errorCallback (const FLAC__FileDecoder *fileDecoder,
+errorCallback (const FLAC__StreamDecoder *fileDecoder,
                FLAC__StreamDecoderErrorStatus status,
                void *clientData)
 {
@@ -161,25 +161,24 @@ errorCallback (const FLAC__FileDecoder *
 
 - (BOOL) _initializeFileDecoderWithFilename: (NSString *) fileName
 {
-  FLAC__file_decoder_set_metadata_ignore_all (fileDecoder);
-  FLAC__file_decoder_set_metadata_respond (fileDecoder,
+  FLAC__stream_decoder_set_metadata_ignore_all (fileDecoder);
+  FLAC__stream_decoder_set_metadata_respond (fileDecoder,
                                            FLAC__METADATA_TYPE_STREAMINFO);
-  FLAC__file_decoder_set_metadata_callback (fileDecoder,
-                                            metadataCallback);
-  FLAC__file_decoder_set_write_callback (fileDecoder, writeCallback);
-  FLAC__file_decoder_set_error_callback (fileDecoder, errorCallback);
-  FLAC__file_decoder_set_client_data (fileDecoder, self);
-
-  return (FLAC__file_decoder_set_filename (fileDecoder, [fileName cString])
-          && (FLAC__file_decoder_init (fileDecoder) == FLAC__FILE_DECODER_OK)
-          && FLAC__file_decoder_process_until_end_of_metadata (fileDecoder));
+  return (FLAC__stream_decoder_init_file (fileDecoder,
+					  [fileName cString],
+					  writeCallback,
+					  metadataCallback,
+					  errorCallback,
+					  self)
+	  == FLAC__STREAM_DECODER_INIT_STATUS_OK)
+    && FLAC__stream_decoder_process_until_end_of_metadata (fileDecoder);
 }
 
 - (BOOL) streamOpen: (NSString *) fileName
 {
   BOOL result;
 
-  fileDecoder = FLAC__file_decoder_new();
+  fileDecoder = FLAC__stream_decoder_new();
 
   if (fileDecoder)
     {
@@ -187,7 +186,7 @@ errorCallback (const FLAC__FileDecoder *
         result = YES;
       else
         {
-          FLAC__file_decoder_delete (fileDecoder);
+          FLAC__stream_decoder_delete (fileDecoder);
           fileDecoder = NULL;
           result = NO;
         }
@@ -200,7 +199,7 @@ errorCallback (const FLAC__FileDecoder *
 
 - (void) streamClose
 {
-  FLAC__file_decoder_delete (fileDecoder);
+  FLAC__stream_decoder_delete (fileDecoder);
   fileDecoder = NULL;
 }
 
@@ -215,7 +214,7 @@ errorCallback (const FLAC__FileDecoder *
   if (position >= readBufferSize)
     {
       position = 0;
-      success = FLAC__file_decoder_process_single (fileDecoder);
+      success = FLAC__stream_decoder_process_single (fileDecoder);
     }
 
   if (success)
@@ -251,13 +250,13 @@ errorCallback (const FLAC__FileDecoder *
              withSize: (unsigned int) bufferSize
 {
   int readBytes;
-  FLAC__FileDecoderState state;
+  FLAC__StreamDecoderState state;
 
-  state = FLAC__file_decoder_get_state (fileDecoder);
+  state = FLAC__stream_decoder_get_state (fileDecoder);
 
-  if (state == FLAC__FILE_DECODER_OK)
+  if (state == FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC)
     readBytes = [self _processNextChunk: buffer withSize: bufferSize];
-  else if (state == FLAC__FILE_DECODER_END_OF_FILE)
+  else if (state == FLAC__STREAM_DECODER_END_OF_STREAM)
     readBytes = 0;
   else
     readBytes = -1;
@@ -272,7 +271,7 @@ errorCallback (const FLAC__FileDecoder *
 
 - (void) seek: (unsigned int) aPos
 {
-  FLAC__file_decoder_seek_absolute (fileDecoder, aPos * rate);
+  FLAC__stream_decoder_seek_absolute (fileDecoder, aPos * rate);
 }
 
 - (unsigned int) readChannels
@@ -295,7 +294,7 @@ errorCallback (const FLAC__FileDecoder *
   if (readBuffer)
     free (readBuffer);
   if (fileDecoder)
-    FLAC__file_decoder_delete (fileDecoder);
+    FLAC__stream_decoder_delete (fileDecoder);
   [super dealloc];
 }
 
