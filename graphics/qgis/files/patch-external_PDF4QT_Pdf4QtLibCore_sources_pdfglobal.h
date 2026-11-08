--- external/PDF4QT/Pdf4QtLibCore/sources/pdfglobal.h.orig	2026-07-31 12:30:19 UTC
+++ external/PDF4QT/Pdf4QtLibCore/sources/pdfglobal.h
@@ -130,7 +130,16 @@ struct PDFObjectReference
     constexpr bool isValid() const { return objectNumber > 0; }
 };
 
+
 /// Represents version identification
+
+#ifdef major
+#undef major
+#endif
+#ifdef minor
+#undef minor
+#endif
+
 struct PDFVersion
 {
     constexpr explicit PDFVersion() = default;
