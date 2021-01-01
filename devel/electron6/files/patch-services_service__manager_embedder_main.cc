--- services/service_manager/embedder/main.cc.orig	2019-09-10 11:14:12 UTC
+++ services/service_manager/embedder/main.cc
@@ -271,7 +271,7 @@ int Main(const MainParams& params) {
 #endif
     base::EnableTerminationOnOutOfMemory();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
