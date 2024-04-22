--- components/os_crypt/sync/libsecret_util_linux.cc.orig	2023-05-25 00:41:51 UTC
+++ components/os_crypt/sync/libsecret_util_linux.cc
@@ -99,16 +99,22 @@ bool LibsecretLoader::EnsureLibsecretLoaded() {
 
 // static
 bool LibsecretLoader::LoadLibsecret() {
+#if BUILDFLAG(IS_BSD)
+  const char* kSecretLib = "libsecret-1.so";
+#else
+  const char* kSecretLib = "libsecret-1.so.0";
+#endif
+
   if (libsecret_loaded_)
     return true;
 
-  static void* handle = dlopen("libsecret-1.so.0", RTLD_NOW | RTLD_GLOBAL);
+  static void* handle = dlopen(kSecretLib, RTLD_NOW | RTLD_GLOBAL);
   if (!handle) {
     // We wanted to use libsecret, but we couldn't load it. Warn, because
     // either the user asked for this, or we autodetected it incorrectly. (Or
     // the system has broken libraries, which is also good to warn about.)
     // TODO(crbug.com/607435): Channel this message to the user-facing log
-    VLOG(1) << "Could not load libsecret-1.so.0: " << dlerror();
+    VLOG(1) << "Could not load << " << kSecretLib << ": " << dlerror();
     return false;
   }
 
