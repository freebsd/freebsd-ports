--- core/com/lowagie/text/pdf/PRTokeniser.java.orig	2012-07-03 16:02:24.000000000 +0200
+++ core/com/lowagie/text/pdf/PRTokeniser.java	2012-07-03 16:03:30.000000000 +0200
@@ -281,6 +281,12 @@
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
