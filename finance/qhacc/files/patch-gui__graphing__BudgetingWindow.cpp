--- gui/graphing/BudgetingWindow.cpp.orig
+++ gui/graphing/BudgetingWindow.cpp
@@ -120,7 +120,11 @@
     }
   }
 
+#if defined(QWT_VERSION) && QWT_VERSION>=0x060100
+  const QwtScaleDiv * div = &widget.qwtPlot->axisScaleDiv( QwtPlot::xBottom );
+#else
   QwtScaleDiv * div = widget.qwtPlot->axisScaleDiv( QwtPlot::xBottom );
+#endif
   div->setInterval( 0, drawer->count() );
   widget.qwtPlot->setAxisMaxMajor( QwtPlot::xBottom, drawer->count() );
 
