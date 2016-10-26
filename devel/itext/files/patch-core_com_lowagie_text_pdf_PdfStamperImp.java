--- core/com/lowagie/text/pdf/PdfStamperImp.java.orig	2016-10-26 08:23:27 UTC
+++ core/com/lowagie/text/pdf/PdfStamperImp.java
@@ -208,13 +208,22 @@ class PdfStamperImp extends PdfWriter {
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
         if (oldInfo != null && oldInfo.get(PdfName.PRODUCER) != null)
-        	producer = oldInfo.getAsString(PdfName.PRODUCER).toString();
+        	producer = oldInfo.getAsString(PdfName.PRODUCER).toUnicodeString();
         if (producer == null) {
         	producer = Document.getVersion();
         }
@@ -343,7 +352,7 @@ class PdfStamperImp extends PdfWriter {
             }
         }
         newInfo.put(PdfName.MODDATE, date);
-        newInfo.put(PdfName.PRODUCER, new PdfString(producer));
+        newInfo.put(PdfName.PRODUCER, new PdfString(producer, PdfObject.TEXT_UNICODE));
         if (append) {
             if (iInfo == null)
                 info = addToBody(newInfo, false).getIndirectReference();
