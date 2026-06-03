--- c++/test/TestConvertColumnReader.cc.orig	2025-09-29 08:02:24 UTC
+++ c++/test/TestConvertColumnReader.cc
@@ -1019,7 +1019,7 @@ namespace orc {
     auto h = second_in_day % (3600 * 24) / 3600;
     auto min = second_in_day % 3600 / 60;
     auto s = second_in_day % 60;
-    std::snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d %02ld:%02ld:%02ld", y, m, d, h, min, s);
+    std::snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d %02ld:%02ld:%02ld", y, m, d, (long)h, (long)min, (long)s);
     std::string result(buffer);
     if (nanos) {
       while (nanos % 10 == 0) nanos /= 10;
