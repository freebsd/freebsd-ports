--- src/extractors/plaintextextractor.cpp.orig	2025-08-01 10:34:24 UTC
+++ src/extractors/plaintextextractor.cpp
@@ -119,7 +119,7 @@ void PlainTextExtractor::extract(ExtractionResult* res
 
     // Read the first chunk, detect the encoding and decode it
     QByteArray chunk(256 * 1024, Qt::Uninitialized);
-    auto size = file.read(chunk.data(), chunk.size());
+    auto size = static_cast<qsizetype>(file.read(chunk.data(), chunk.size()));
 
     QStringDecoder codec{autodetectCodec({chunk.data(), size})};
 
@@ -151,7 +151,7 @@ void PlainTextExtractor::extract(ExtractionResult* res
 
     // Read and decode the remainder
     while (!file.atEnd()) {
-        auto size = file.read(chunk.data(), chunk.size());
+        auto size = static_cast<qsizetype>(file.read(chunk.data(), chunk.size()));
         if (size < 0) {
             // may happen when the file is truncated during read
             qCWarning(KFILEMETADATA_LOG) << "Error reading" << result->inputUrl();
