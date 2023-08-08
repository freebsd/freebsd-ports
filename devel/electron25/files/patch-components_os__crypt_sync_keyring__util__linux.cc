--- components/os_crypt/sync/keyring_util_linux.cc.orig	2023-05-25 00:41:51 UTC
+++ components/os_crypt/sync/keyring_util_linux.cc
@@ -65,15 +65,21 @@ const GnomeKeyringLoader::FunctionInfo GnomeKeyringLoa
 
 /* Load the library and initialize the function pointers. */
 bool GnomeKeyringLoader::LoadGnomeKeyring() {
+#if BUILDFLAG(IS_BSD)
+  const char* kGkr = "libgnome-keyring.so";
+#else
+  const char* kGkr = "libgnome-keyring.so.0";
+#endif
+
   if (keyring_loaded)
     return true;
 
-  void* handle = dlopen("libgnome-keyring.so.0", RTLD_NOW | RTLD_GLOBAL);
+  void* handle = dlopen(kGkr, RTLD_NOW | RTLD_GLOBAL);
   if (!handle) {
     // We wanted to use GNOME Keyring, but we couldn't load it. Warn, because
     // either the user asked for this, or we autodetected it incorrectly. (Or
     // the system has broken libraries, which is also good to warn about.)
-    LOG(WARNING) << "Could not load libgnome-keyring.so.0: " << dlerror();
+    LOG(WARNING) << "Could not load " << kGkr << ": " << dlerror();
     return false;
   }
 
