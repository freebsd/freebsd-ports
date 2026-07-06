--- src/util/io/decompressor.h.orig	2026-06-22 21:46:21 UTC
+++ src/util/io/decompressor.h
@@ -79,7 +79,7 @@ struct PassThrough : Decompressor {
 		return std::fread(buffer, size, count, stream);
 	}
 	int fgetc(FILE* stream) override {
-#if defined(_MSC_VER) || defined(__APPLE__)
+#if defined(_MSC_VER) || defined(__APPLE__) || defined(__FreeBSD__)
 		return std::fgetc(stream);
 #else
 		return fgetc_unlocked(stream);
@@ -141,4 +142,4 @@ struct ZstdDecompressor : Decompressor { (private)
 	bool eos_ = false;
 	int pushback_ = EOF;
 };
-#endif
\ No newline at end of file
+#endif
