--- poppler/FlateStream.cc.orig	2025-04-09 19:16:40 UTC
+++ poppler/FlateStream.cc
@@ -133,18 +133,22 @@ int FlateStream::fill_buffer()
     return 0;
 }
 
-GooString *FlateStream::getPSFilter(int psLevel, const char *indent)
+std::optional<std::string> FlateStream::getPSFilter(int psLevel, const char *indent)
 {
-    GooString *s;
-
     if (psLevel < 3 || pred) {
-        return NULL;
+        return std::nullopt;
     }
-    if (!(s = str->getPSFilter(psLevel, indent))) {
-        return NULL;
+
+    auto inner = str->getPSFilter(psLevel, indent);
+    if (!inner.has_value()) {
+        return std::nullopt;
     }
-    s->append(indent)->append("<< >> /FlateDecode filter\n");
-    return s;
+
+    std::string result = *inner;
+    result.append(indent);
+    result.append("<< >> /FlateDecode filter\n");
+
+    return result;
 }
 
 bool FlateStream::isBinary(bool last) const
