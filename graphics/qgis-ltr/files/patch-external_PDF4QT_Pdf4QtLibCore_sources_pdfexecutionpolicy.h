--- external/PDF4QT/Pdf4QtLibCore/sources/pdfexecutionpolicy.h.orig	2026-07-31 12:30:19 UTC
+++ external/PDF4QT/Pdf4QtLibCore/sources/pdfexecutionpolicy.h
@@ -138,7 +138,7 @@ class PDF4QTLIBCORESHARED_EXPORT PDFExecutionPolicy (p
         }
         else
         {
-            std::for_each(std::execution::seq, first, last, f);
+            std::for_each(first, last, f);
         }
     }
 
