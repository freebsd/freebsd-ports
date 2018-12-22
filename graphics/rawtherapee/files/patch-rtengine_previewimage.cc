Fixes high idle CPU usage with libomp
https://github.com/Beep6581/RawTherapee/issues/5105

--- rtengine/previewimage.cc.orig	2018-12-18 19:27:33 UTC
+++ rtengine/previewimage.cc
@@ -119,7 +119,7 @@ PreviewImage::PreviewImage (const Glib::ustring &fname
             rawImage.getImage (wb, TR_NONE, &image, pp, params.toneCurve, params.raw);
             rtengine::Image8 output(fw, fh);
             rawImage.convertColorSpace(&image, params.icm, wb);
-            #pragma omp parallel for schedule(dynamic, 10)
+            #pragma omp parallel for
             for (int i = 0; i < fh; ++i)
                 for (int j = 0; j < fw; ++j) {
                     image.r(i, j) = Color::gamma2curve[image.r(i, j)];
