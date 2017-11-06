--- src/musicbrainz/chromaprinter.cpp.orig	2015-12-29 16:10:41 UTC
+++ src/musicbrainz/chromaprinter.cpp
@@ -57,12 +57,12 @@ QString ChromaPrinter::calcFingerPrint(c
     }
     chromaprint_finish(ctx);
 
-    void* fprint = NULL;
+    unsigned int* fprint = NULL;
     int size = 0;
     int ret = chromaprint_get_raw_fingerprint(ctx, &fprint, &size);
     QByteArray fingerprint;
     if (ret == 1) {
-        void* encoded = NULL;
+        char* encoded = NULL;
         int encoded_size = 0;
         chromaprint_encode_fingerprint(fprint, size,
                                        CHROMAPRINT_ALGORITHM_DEFAULT,
