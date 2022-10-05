- workaround for https://github.com/llvm/llvm-project/issues/55683

--- src/util/fs_util.cpp.orig	2022-05-29 18:00:44 UTC
+++ src/util/fs_util.cpp
@@ -8,10 +8,10 @@ std::optional<std::string> get_relative_filename(const
 {
     const auto p = fs::u8path(path);
     const auto b = fs::u8path(base);
-    const auto x = std::search(p.begin(), p.end(), b.begin(), b.end());
-    if (x == p.begin()) // path is in base path
-        return fs::relative(p, b).u8string();
-    else
-        return {};
+    for (auto ip = p.begin(), ib = b.begin(); ib != b.end(); ip++, ib++) {
+        if (ip == p.end() || *ip != *ib)
+            return {};
+    }
+    return fs::relative(p, b).u8string();
 }
 } // namespace horizon
