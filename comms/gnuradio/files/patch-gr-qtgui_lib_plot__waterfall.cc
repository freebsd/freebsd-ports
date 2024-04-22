--- gr-qtgui/lib/plot_waterfall.cc.orig	2024-02-19 05:22:53 UTC
+++ gr-qtgui/lib/plot_waterfall.cc
@@ -252,7 +252,11 @@ QImage PlotWaterfall::renderImage(const QwtScaleMap& x
             }
         }
     } else if (d_data->colorMap->format() == QwtColorMap::Indexed) {
+#if QWT_VERSION >= 0x060200
+        image.setColorTable(d_data->colorMap->colorTable(256));
+#else
         image.setColorTable(d_data->colorMap->colorTable(intensityRange));
+#endif
 
         for (int y = rect.top(); y <= rect.bottom(); y++) {
             const double ty = yyMap.invTransform(y);
@@ -261,8 +265,13 @@ QImage PlotWaterfall::renderImage(const QwtScaleMap& x
             for (int x = rect.left(); x <= rect.right(); x++) {
                 const double tx = xxMap.invTransform(x);
 
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
