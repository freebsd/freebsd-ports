--- external/lazperf/lazperf/writers.cpp.orig	2025-12-30 20:32:06 UTC
+++ external/lazperf/lazperf/writers.cpp
@@ -196,7 +196,15 @@ void basic_file::Private::writeHeader()
 void basic_file::Private::writeHeader()
 {
     laz_vlr lazVlr(head14.pointFormat(), head14.ebCount(), chunk_size);
-    eb_vlr ebVlr(head14.ebCount());
+    eb_vlr ebVlr;
+
+    for (int i = 0; i < head14.ebCount(); ++i)
+    {
+        eb_vlr::ebfield field;
+
+        field.name = "FIELD_" + std::to_string(i);
+        ebVlr.addField(field);
+    }
 
     // Set the version number to 2 in order to write something reasonable.
     if (head14.version.minor < 2 || head14.version.minor > 4)
