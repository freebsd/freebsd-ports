--- src/snowflake/connector/nanoarrow_cpp/ArrowIterator/nanoarrow_ipc.h.orig	2023-11-30 19:16:47 UTC
+++ src/snowflake/connector/nanoarrow_cpp/ArrowIterator/nanoarrow_ipc.h
@@ -193,7 +193,7 @@ void ArrowIpcDecoderReset(struct ArrowIpcDecoder* deco
 /// The first 8 bytes of an Arrow IPC message are 0xFFFFFF followed by the size
 /// of the header as a little-endian 32-bit integer. ArrowIpcDecoderPeekHeader() reads
 /// these bytes and returns ESPIPE if there are not enough remaining bytes in data to read
-/// the entire header message, EINVAL if the first 8 bytes are not valid, ENODATA if the
+/// the entire header message, EINVAL if the first 8 bytes are not valid, ENOATTR if the
 /// Arrow end-of-stream indicator has been reached, or NANOARROW_OK otherwise.
 ArrowErrorCode ArrowIpcDecoderPeekHeader(struct ArrowIpcDecoder* decoder,
                                          struct ArrowBufferView data,
