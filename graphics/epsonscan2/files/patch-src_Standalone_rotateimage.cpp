--- src/Standalone/rotateimage.cpp.orig	2024-09-12 07:10:40 UTC
+++ src/Standalone/rotateimage.cpp
@@ -25,37 +25,37 @@ void RotateImage::Rotate(std::string image_path, int a
 void RotateImage::Rotate(std::string image_path, int angle, ImageFormat format, bool multiTiffEnabled, int OFDEnabled)
 {
     std::string file_format;
-    if (format == kSDIImageFormatJPEG)
+    if (format == (ImageFormat)kSDIImageFormatJPEG)
     {
         file_format = "JPG";
-    }else if (format == ImageFormatColorJpegMonoRaw)
+    }else if (format == (ImageFormat)ImageFormatColorJpegMonoRaw)
     {
         if(m_type == ColorTypeMono1){
             file_format = "PBM";
         }else {
             file_format = "JPG";
         }
-    }else if (format == kSDIImageFormatPNM && !multiTiffEnabled)
+    }else if (format == (ImageFormat)kSDIImageFormatPNM && !multiTiffEnabled)
     {
         file_format = "PPM";
-    }else if (format == kSDIImageFormatTIFF)
+    }else if (format == (ImageFormat)kSDIImageFormatTIFF)
     {
         file_format = "TIFF";
-    }else if (format == kSDIImageFormatPNG)
+    }else if (format == (ImageFormat)kSDIImageFormatPNG)
     {
         file_format = "PNG";
-    }else if (format == kSDIImageFormatPNM && multiTiffEnabled)
+    }else if (format == (ImageFormat)kSDIImageFormatPNM && multiTiffEnabled)
     {
         file_format = "PPM";
-    }else if (format == kSDIImageFormatPNM && OFDEnabled)
+    }else if (format == (ImageFormat)kSDIImageFormatPNM && OFDEnabled)
     {
         file_format = "OFD";
     }
     QImage srcImg(image_path.c_str());
     QPoint center = srcImg.rect().center();
-    QMatrix matrix;
-    matrix.translate(center.x(), center.y());
-    matrix.rotate(angle);
-    QImage dstImg = srcImg.transformed(matrix);
+    QTransform transform;
+    transform.translate(center.x(), center.y());
+    transform.rotate(angle);
+    QImage dstImg = srcImg.transformed(transform);
     dstImg.save(QString::fromStdString(image_path), file_format.c_str(), -1);
 }
