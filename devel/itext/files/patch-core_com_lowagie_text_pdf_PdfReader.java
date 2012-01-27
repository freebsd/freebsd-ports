--- core/com/lowagie/text/pdf/PdfReader.java.orig	2012-01-27 11:27:08.000000000 +0100
+++ core/com/lowagie/text/pdf/PdfReader.java	2012-01-27 11:27:41.000000000 +0100
@@ -1464,7 +1464,7 @@
             }
         }
         thisStream *= 2;
-        if (thisStream < xref.length)
+        if (thisStream < xref.length && xref[thisStream] == 0 && xref[thisStream + 1] == 0)
             xref[thisStream] = -1;
 
         if (prev == -1)
