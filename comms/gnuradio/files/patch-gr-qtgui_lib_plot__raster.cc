--- gr-qtgui/lib/plot_raster.cc.orig	2024-02-19 05:21:10 UTC
+++ gr-qtgui/lib/plot_raster.cc
@@ -257,7 +257,11 @@ QImage PlotTimeRaster::renderImage(const QwtScaleMap& 
         }
         d_data->data->incrementResidual();
     } else if (d_data->colorMap->format() == QwtColorMap::Indexed) {
+#if QWT_VERSION >= 0x060200
+        image.setColorTable(d_data->colorMap->colorTable(256));
+#else
         image.setColorTable(d_data->colorMap->colorTable(intensityRange));
+#endif
 
         for (int y = rect.top(); y <= rect.bottom(); y++) {
             const double ty = yyMap.invTransform(y);
@@ -265,9 +269,13 @@ QImage PlotTimeRaster::renderImage(const QwtScaleMap& 
             unsigned char* line = image.scanLine(y - rect.top());
             for (int x = rect.left(); x <= rect.right(); x++) {
                 const double tx = xxMap.invTransform(x);
-
+#if QWT_VERSION >= 0x060200
+                *line++ = d_data->colorMap->colorIndex(
+                    256, intensityRange, d_data->data->value(tx, ty));
+#else
                 *line++ = d_data->colorMap->colorIndex(intensityRange,
                                                        d_data->data->value(tx, ty));
+#endif
             }
         }
     }
