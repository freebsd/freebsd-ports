--- kbarcode/printersettings.cpp.orig	Sat Aug 21 11:08:30 2004
+++ kbarcode/printersettings.cpp	Sat Aug 21 11:08:43 2004
@@ -146,7 +146,7 @@
 int PrinterSettings::getQuality() const
 {
     return lpdata->quality == Middle || lpdata->quality == VeryHigh? High : lpdata->quality;
-};
+}
 
 KPrinter* PrinterSettings::setupPrinter( QWidget* parent, bool immediately, const QString & prn )
 {
