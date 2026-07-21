--- src/util/PathUtil.cpp.orig	2026-07-21 03:37:42 UTC
+++ src/util/PathUtil.cpp
@@ -100,7 +100,11 @@ auto Util::getExePath() -> fs::path {
 #define PATH_MAX 4096
 #endif
     std::array<char, PATH_MAX> result{};
+#if !defined(__FreeBSD__)
     ssize_t count = readlink("/proc/self/exe", result.data(), PATH_MAX);
+#else
+    ssize_t count = readlink("/proc/curproc/file", result.data(), PATH_MAX);
+#endif
     return fs::path{std::string(result.data(), as_unsigned(std::max(ssize_t{0}, count)))}.parent_path();
 }
 #endif
