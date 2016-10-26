--- core/com/lowagie/text/pdf/PdfReader.java.orig	2016-10-26 08:23:27 UTC
+++ core/com/lowagie/text/pdf/PdfReader.java
@@ -1464,7 +1464,7 @@ public class PdfReader implements PdfVie
             }
         }
         thisStream *= 2;
-        if (thisStream < xref.length)
+        if (thisStream < xref.length && xref[thisStream] == 0 && xref[thisStream + 1] == 0)
             xref[thisStream] = -1;
 
         if (prev == -1)
