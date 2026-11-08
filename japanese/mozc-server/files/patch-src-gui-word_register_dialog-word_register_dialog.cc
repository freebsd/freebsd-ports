--- src/gui/word_register_dialog/word_register_dialog.cc.orig	2026-10-18 07:12:43 UTC
+++ src/gui/word_register_dialog/word_register_dialog.cc
@@ -97,9 +97,9 @@ QString GetEnv(const char* envname) {
   }
   return QLatin1String("");
 #endif  // _WIN32
-#if defined(__APPLE__) || defined(__linux__)
+#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
   return QString::fromUtf8(::getenv(envname));
-#endif  // __APPLE__ or __linux__
+#endif  // __APPLE__ || __linux__ || __FreeBSD__
   // TODO(team): Support other platforms.
   return QLatin1String("");
 }
