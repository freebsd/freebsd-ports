--- src/corelib/io/qiodevice.cpp.orig	2020-05-11 08:15:08 UTC
+++ src/corelib/io/qiodevice.cpp
@@ -1480,10 +1480,12 @@ QByteArray QIODevice::readLine(qint64 maxSize)
     } else
         readBytes = readLine(result.data(), result.size());
 
-    if (readBytes <= 0)
+    if (readBytes <= 0) {
         result.clear();
-    else
+    } else {
         result.resize(readBytes);
+        result.squeeze();
+    }
 
     return result;
 }
