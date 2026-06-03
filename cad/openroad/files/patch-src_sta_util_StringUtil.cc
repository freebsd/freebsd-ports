-- std::from_chars for floating-point types is not implemented in FreeBSD's libc++.
-- Replace with std::stof which is available and has equivalent semantics.
-- see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=295767

--- src/sta/util/StringUtil.cc.orig	2026-05-31 21:08:13 UTC
+++ src/sta/util/StringUtil.cc
@@ -55,13 +55,17 @@ stringFloat(const std::string &str)
 std::pair<float, bool>
 stringFloat(const std::string &str)
 {
-  float value;
-  auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), value);
-  if (ec == std::errc()
-      && *ptr == '\0')
-    return {value, true};
-  else
+  // std::from_chars for float is not implemented in FreeBSD libc++
+  try {
+    size_t pos;
+    float value = std::stof(str, &pos);
+    if (pos == str.size())
+      return {value, true};
+    else
+      return {0.0, false};
+  } catch (...) {
     return {0.0, false};
+  }
 }
 
 void
