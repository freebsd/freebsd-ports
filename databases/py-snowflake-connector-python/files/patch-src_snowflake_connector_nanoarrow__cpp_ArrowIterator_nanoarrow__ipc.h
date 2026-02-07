--- src/snowflake/connector/nanoarrow_cpp/ArrowIterator/nanoarrow_ipc.h.orig	2024-04-04 23:04:09 UTC
+++ src/snowflake/connector/nanoarrow_cpp/ArrowIterator/nanoarrow_ipc.h
@@ -198,7 +198,7 @@ void ArrowIpcDecoderReset(struct ArrowIpcDecoder* deco
 /// of the header as a little-endian 32-bit integer. ArrowIpcDecoderPeekHeader()
 /// reads these bytes and returns ESPIPE if there are not enough remaining bytes
 /// in data to read the entire header message, EINVAL if the first 8 bytes are
-/// not valid, ENODATA if the Arrow end-of-stream indicator has been reached, or
+/// not valid, ENOATTR if the Arrow end-of-stream indicator has been reached, or
 /// NANOARROW_OK otherwise.
 ArrowErrorCode ArrowIpcDecoderPeekHeader(struct ArrowIpcDecoder* decoder,
                                          struct ArrowBufferView data,
