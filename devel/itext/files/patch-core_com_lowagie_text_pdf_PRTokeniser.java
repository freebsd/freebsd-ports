--- core/com/lowagie/text/pdf/PRTokeniser.java.orig	2016-06-20 15:02:42 UTC
+++ core/com/lowagie/text/pdf/PRTokeniser.java
@@ -281,6 +281,12 @@ public class PRTokeniser {
                 }
             }
         }
+        if (level > 0) {
+            file.seek(ptr);
+            type = TK_NUMBER;
+            stringValue = n1;
+            return;
+        }
         // if we hit here, the file is either corrupt (stream ended unexpectedly),
         // or the last token ended exactly at the end of a stream.  This last
         // case can occur inside an Object Stream.
