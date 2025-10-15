Update ITK enum name for ITK 5.0 compatibility.

ITK 5.0 renamed IOByteOrderEnum to ByteOrder.

--- common/rtkEdfImageIO.h.orig	2025-04-17 12:54:38 UTC
+++ common/rtkEdfImageIO.h
@@ -100,7 +100,7 @@ class EdfImageIO : public itk::ImageIOBase (protected)
   // table key-value structure
   struct table {
     const char *key;
-    itk::ImageIOBase::IOByteOrderEnum value;
+    itk::ImageIOBase::ByteOrder value;
     };
 
   struct table3 {
