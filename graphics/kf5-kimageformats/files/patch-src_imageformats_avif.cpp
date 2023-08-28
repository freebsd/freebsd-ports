src/imageformats/avif.cpp:428:40: error: no member named 'mode' in 'avifImageMirror'
        switch (m_decoder->image->imir.mode) {
                ~~~~~~~~~~~~~~~~~~~~~~ ^

--- src/imageformats/avif.cpp.orig	2023-08-05 12:37:26 UTC
+++ src/imageformats/avif.cpp
@@ -424,7 +424,7 @@ bool QAVIFHandler::decode_one_frame()
     }
 
     if (m_decoder->image->transformFlags & AVIF_TRANSFORM_IMIR) {
-#if AVIF_VERSION > 90100
+#if AVIF_VERSION > 90100 && AVIF_VERSION < 1000000
         switch (m_decoder->image->imir.mode) {
 #else
         switch (m_decoder->image->imir.axis) {
