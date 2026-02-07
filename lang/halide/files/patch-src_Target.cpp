--- src/Target.cpp.orig	2024-02-20 17:13:06 UTC
+++ src/Target.cpp
@@ -148,6 +148,9 @@ Target calculate_host_target() {
 #ifdef __linux__
     os = Target::Linux;
 #endif
+#ifdef __FreeBSD__
+    os = Target::FreeBSD;
+#endif
 #ifdef _WIN32
     os = Target::Windows;
 #endif
@@ -399,6 +402,7 @@ const std::map<std::string, Target::OS> os_name_map = 
 const std::map<std::string, Target::OS> os_name_map = {
     {"os_unknown", Target::OSUnknown},
     {"linux", Target::Linux},
+    {"freebsd", Target::FreeBSD},
     {"windows", Target::Windows},
     {"osx", Target::OSX},
     {"android", Target::Android},
