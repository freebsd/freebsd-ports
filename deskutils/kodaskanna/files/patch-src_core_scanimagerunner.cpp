--- src/core/scanimagerunner.cpp.orig	2025-01-17 13:30:11 UTC
+++ src/core/scanimagerunner.cpp
@@ -62,7 +62,7 @@ ZXing::ImageFormat zxingImageFormatFromQImage(const QI
 }
 
 #if ZXING_VERSION >= QT_VERSION_CHECK(2, 2, 0)
-ZXing::Result readBarcode(const QImage &image, const ZXing::ReaderOptions &readerOptions)
+ZXing::Barcode readBarcode(const QImage &image, const ZXing::ReaderOptions &readerOptions)
 {
     return ZXing::ReadBarcode({image.bits(), image.width(), image.height(), zxingImageFormatFromQImage(image), static_cast<int>(image.bytesPerLine())}, readerOptions);
 }
@@ -80,7 +80,7 @@ void ScanImageRunner::run()
     readerOptions.setFormats(ZXing::BarcodeFormat::Any);
 
     const bool isSupportedQImageFormat = (zxingImageFormatFromQImage(m_image) == ZXing::ImageFormat::None);
-    ZXing::Result result =
+    ZXing::Barcode result =
         isSupportedQImageFormat ? readBarcode(m_image.convertToFormat(QImage::Format_RGBX8888), readerOptions) : readBarcode(m_image, readerOptions);
 #else
     ZXing::DecodeHints decodeHints;
