--- ext/gd/libgd/gd_gif_out.c.orig	Sat Jun 28 15:47:56 2003
+++ ext/gd/libgd/gd_gif_out.c	Sat Jun 28 16:07:33 2003
@@ -0,0 +1,70 @@
+#include <stdio.h>
+#include <math.h>
+#include <string.h>
+#include <stdlib.h>
+#include "gd.h"
+
+/*
+** Wrapper functions for GIF output.
+*/
+
+void gdImageGifToSink(gdImagePtr im, gdSinkPtr outSink)
+{
+        gdIOCtx   *out = gdNewSSCtx(NULL,outSink);
+        gdImageGifCtx(im, out);
+        out->gd_free(out);
+}
+
+void gdImageGifCtx(gdImagePtr im, gdIOCtx *out)
+{
+#ifdef LZW_LICENCED
+	gdImageLzwCtx(im, out);
+#else
+        gdImageBigGifCtx(im, out);
+#endif
+}
+
+void gdImageGif(gdImagePtr im, FILE *outFile)
+{
+#ifdef LZW_LICENCED
+        gdImageLzw(im, outFile);
+#else
+        gdImageBigGif(im, outFile);
+#endif
+}
+
+void* gdImageGifPtr(gdImagePtr im, int *size)
+{
+#ifdef LZW_LICENCED
+        return gdImageLzwPtr(im, size);
+#else
+        return gdImageBigGifPtr(im, size);
+#endif
+}
+
+void gdImageGifAnimAddCtx(gdImagePtr im, gdIOCtx *out, int LocalCM, int LeftOfs, int TopOfs, int Delay, int Disposal)
+{
+#ifdef LZW_LICENCED
+	gdImageLzwAnimAddCtx(im, out, LocalCM, LeftOfs, TopOfs, Delay, Disposal);
+#else
+	gdImageBigGifAnimAddCtx(im, out, LocalCM, LeftOfs, TopOfs, Delay, Disposal);
+#endif
+}
+
+void gdImageGifAnimAdd(gdImagePtr im, FILE *outFile, int LocalCM, int LeftOfs, int TopOfs, int Delay, int Disposal)
+{
+#ifdef LZW_LICENCED
+	gdImageLzwAnimAdd(im, outFile, LocalCM, LeftOfs, TopOfs, Delay, Disposal);
+#else
+	gdImageBigGifAnimAdd(im, outFile, LocalCM, LeftOfs, TopOfs, Delay, Disposal);
+#endif
+}
+
+void *gdImageGifAnimAddPtr(gdImagePtr im, int *size, int LocalCM, int LeftOfs, int TopOfs, int Delay, int Disposal)
+{
+#ifdef LZW_LICENCED
+	return gdImageLzwAnimAddPtr(im, size, LocalCM, LeftOfs, TopOfs, Delay, Disposal);
+#else
+	return gdImageBigGifAnimAddPtr(im, size, LocalCM, LeftOfs, TopOfs, Delay, Disposal);
+#endif
+}
