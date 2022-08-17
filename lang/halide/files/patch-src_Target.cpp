--- src/Target.cpp.orig	2022-08-17 04:41:42 UTC
+++ src/Target.cpp
@@ -67,6 +67,9 @@ Target calculate_host_target() {
 #ifdef __linux__
     os = Target::Linux;
 #endif
+#ifdef __FreeBSD__
+    os = Target::FreeBSD;
+#endif
 #ifdef _WIN32
     os = Target::Windows;
 #endif
@@ -269,6 +272,7 @@ Target::Feature get_host_cuda_capability(Target t) {
 const std::map<std::string, Target::OS> os_name_map = {
     {"os_unknown", Target::OSUnknown},
     {"linux", Target::Linux},
+    {"freebsd", Target::FreeBSD},
     {"windows", Target::Windows},
     {"osx", Target::OSX},
     {"android", Target::Android},
