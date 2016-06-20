--- core/com/lowagie/text/pdf/PdfStamperImp.java.orig	2016-06-20 15:02:42 UTC
+++ core/com/lowagie/text/pdf/PdfStamperImp.java
@@ -208,8 +208,17 @@ class PdfStamperImp extends PdfWriter {
         }
         // metadata
         int skipInfo = -1;
-        PRIndirectReference iInfo = (PRIndirectReference)reader.getTrailer().get(PdfName.INFO);
-        PdfDictionary oldInfo = (PdfDictionary)PdfReader.getPdfObject(iInfo);
+        PRIndirectReference iInfo = null;
+        PdfDictionary oldInfo;
+        PdfObject dictInfo = reader.getTrailer().get(PdfName.INFO);
+        // Info dictionary in the trailer shall be an indirect reference,
+        // but a few broken softwares put it inline
+        if (dictInfo instanceof PdfDictionary) {
+            oldInfo = (PdfDictionary) dictInfo;
+        } else {
+            iInfo = (PRIndirectReference) dictInfo;
+            oldInfo = (PdfDictionary)PdfReader.getPdfObject(iInfo);
+        }
         String producer = null;
         if (iInfo != null)
             skipInfo = iInfo.getNumber();
