--- src/snowflake/connector/nanoarrow_cpp/ArrowIterator/nanoarrow_ipc.c.orig	2023-11-30 19:17:00 UTC
+++ src/snowflake/connector/nanoarrow_cpp/ArrowIterator/nanoarrow_ipc.c
@@ -21239,7 +21239,7 @@ static inline int ArrowIpcDecoderReadHeaderPrefix(stru
 
   if (header_body_size_bytes == 0) {
     ArrowErrorSet(error, "End of Arrow stream");
-    return ENODATA;
+    return ENOATTR;
   }
 
   return NANOARROW_OK;
@@ -22194,7 +22194,7 @@ static int ArrowIpcArrayStreamReaderNextHeader(
     // is one of the valid outcomes) but we set the error anyway in case it gets
     // propagated higher (e.g., if the stream is empty and there's no schema message)
     ArrowErrorSet(&private_data->error, "No data available on stream");
-    return ENODATA;
+    return ENOATTR;
   } else if (bytes_read != 8) {
     ArrowErrorSet(&private_data->error,
                   "Expected at least 8 bytes in remainder of stream");
@@ -22338,7 +22338,7 @@ static int ArrowIpcArrayStreamReaderGetNext(struct Arr
   // Read + decode the next header
   int result = ArrowIpcArrayStreamReaderNextHeader(
       private_data, NANOARROW_IPC_MESSAGE_TYPE_RECORD_BATCH);
-  if (result == ENODATA) {
+  if (result == ENOATTR) {
     // Stream is finished either because there is no input or because
     // end of stream bytes were read.
     out->release = NULL;
