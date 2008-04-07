--- Bundles/FLACTags/FLACTags.m.orig	2006-03-21 22:41:04.000000000 +0100
+++ Bundles/FLACTags/FLACTags.m	2008-03-27 17:23:35.000000000 +0100
@@ -78,14 +78,14 @@ processComment (FLAC__StreamMetadata_Vor
 }
 
 static FLAC__StreamDecoderWriteStatus
-writeCallback (const FLAC__FileDecoder *fileDecoder, const FLAC__Frame *frame,
+writeCallback (const FLAC__StreamDecoder *fileDecoder, const FLAC__Frame *frame,
                const FLAC__int32 * const buffer[], void *clientData)
 {
   return FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE;
 }
 
 static void
-metadataCallback (const FLAC__FileDecoder *fileDecoder,
+metadataCallback (const FLAC__StreamDecoder *fileDecoder,
                   const FLAC__StreamMetadata *metadata,
                   void *clientData)
 {
@@ -104,7 +104,7 @@ metadataCallback (const FLAC__FileDecode
 }
 
 static void
-errorCallback (const FLAC__FileDecoder *fileDecoder,
+errorCallback (const FLAC__StreamDecoder *fileDecoder,
                FLAC__StreamDecoderErrorStatus status,
                void *clientData)
 {
@@ -132,30 +132,25 @@ errorCallback (const FLAC__FileDecoder *
               year: (NSString **) year
         ofFilename: (NSString *) filename
 {
-  FLAC__FileDecoder *fileDecoder;
+  FLAC__StreamDecoder *fileDecoder;
   BOOL result;
   NSString **arrayOfValues[] = { title, artist, album, trackNumber,
                                  genre, year };
 
-  fileDecoder = FLAC__file_decoder_new();
+  fileDecoder = FLAC__stream_decoder_new();
   if (fileDecoder)
     {
-      FLAC__file_decoder_set_metadata_ignore_all (fileDecoder);
-      FLAC__file_decoder_set_metadata_respond (fileDecoder,
+      FLAC__stream_decoder_set_metadata_ignore_all (fileDecoder);
+      FLAC__stream_decoder_set_metadata_respond (fileDecoder,
                                                FLAC__METADATA_TYPE_VORBIS_COMMENT);
-      FLAC__file_decoder_set_metadata_callback (fileDecoder,
-                                                metadataCallback);
-      FLAC__file_decoder_set_write_callback (fileDecoder, writeCallback);
-      FLAC__file_decoder_set_error_callback (fileDecoder, errorCallback);
-      FLAC__file_decoder_set_client_data (fileDecoder, arrayOfValues);
-
-      result = (FLAC__file_decoder_set_filename (fileDecoder,
-                                                 [filename cString])
-                && (FLAC__file_decoder_init (fileDecoder)
-                    == FLAC__FILE_DECODER_OK)
-                && FLAC__file_decoder_process_until_end_of_metadata
-                (fileDecoder));
-      FLAC__file_decoder_delete (fileDecoder);
+      result = (FLAC__stream_decoder_init_file (fileDecoder,
+						[filename cString],
+						writeCallback,					                               metadataCallback,
+						errorCallback,
+						*arrayOfValues)
+		== FLAC__STREAM_DECODER_INIT_STATUS_OK)
+	&& FLAC__stream_decoder_process_until_end_of_metadata (fileDecoder);
+      FLAC__stream_decoder_delete (fileDecoder);
     }
   else
     result = NO;
