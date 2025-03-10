--- libs/process/src/ext/exe.cpp.orig	2024-12-05 00:53:35 UTC
+++ libs/process/src/ext/exe.cpp
@@ -138,7 +138,7 @@ filesystem::path exe(boost::process::v2::pid_type pid,
             filesystem::path("/proc") / std::to_string(pid) / "exe", ec
             );
 #elif defined(__sun)
-    return fileystem::canonical(
+    return filesystem::canonical(
             filesystem::path("/proc") / std::to_string(pid) / "path/a.out", ec
             );
 #endif
