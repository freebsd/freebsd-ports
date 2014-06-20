--- src/common/ffmpeg.cpp.orig	2014-04-29 21:21:05.929639513 -0700
+++ src/common/ffmpeg.cpp	2014-04-29 21:26:22.513617805 -0700
@@ -178,17 +178,31 @@
     // make sure RGB is supported (mostly not)
     if(codec->pix_fmts) {
 	const enum PixelFormat *p;
+#if LIBAVCODEC_VERSION_MAJOR < 55
 	int64_t mask = 0;
+#endif
 	for(p = codec->pix_fmts; *p != -1; p++) {
 	    // may get complaints about 1LL; thus the cast
+#if LIBAVCODEC_VERSION_MAJOR < 55
 	    mask |= ((int64_t)1) << *p;
+#endif
 	    if(*p == pixfmt)
 		break;
 	}
 	if(*p == -1) {
 	    // if not supported, use a converter to the next best format
 	    // this is swscale, the converter used by the output demo
+#if LIBAVCODEC_VERSION_MAJOR < 55
 	    enum PixelFormat dp = (PixelFormat)avcodec_find_best_pix_fmt(mask, pixfmt, 0, NULL);
+#else
+#if LIBAVCODEC_VERSION_MICRO >= 100
+// FFmpeg
+	    enum AVPixelFormat dp = avcodec_find_best_pix_fmt_of_list(codec->pix_fmts, pixfmt, 0, NULL);
+#else
+// libav
+	    enum AVPixelFormat dp = avcodec_find_best_pix_fmt2(codec->pix_fmts, pixfmt, 0, NULL);
+#endif
+#endif
 	    if(dp == -1)
 		dp = codec->pix_fmts[0];
 	    if(!(convpic = avcodec_alloc_frame()) ||
