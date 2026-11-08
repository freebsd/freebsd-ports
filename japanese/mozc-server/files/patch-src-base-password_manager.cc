--- src/base/password_manager.cc.orig	2026-10-17 19:51:09 UTC
+++ src/base/password_manager.cc
@@ -264,9 +264,9 @@ bool WinMacPasswordManager::RemovePassword() { return 
 // We use plain text file for password storage on Linux. If you port this module
 // to other Linux distro, you might want to implement a new password manager
 // which adopts some secure mechanism such like gnome-keyring.
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__FreeBSD__)
 typedef PlainPasswordManager DefaultPasswordManager;
-#endif  // __linux__ || __wasm__
+#endif  // __linux__ || __wasm__ || __FreeBSD__
 
 // Windows or Mac
 #if (defined(_WIN32) || defined(__APPLE__))
