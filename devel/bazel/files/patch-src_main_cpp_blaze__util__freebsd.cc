--- src/main/cpp/blaze_util_freebsd.cc.orig	1979-12-31 23:00:00 UTC
+++ src/main/cpp/blaze_util_freebsd.cc
@@ -145,6 +145,9 @@ bool IsSharedLibrary(const string &filen
 
 string GetDefaultHostJavabase() {
   // if JAVA_HOME is defined, then use it as default.
+  if (getenv("JAVA_HOME") == nullptr) {
+    return "/usr/local/openjdk8";
+  }
   string javahome = getenv("JAVA_HOME");
   return !javahome.empty() ? javahome : "/usr/local/openjdk8";
 }
