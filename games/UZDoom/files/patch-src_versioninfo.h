--- src/versioninfo.h.orig	2026-09-22 20:08:22 UTC
+++ src/versioninfo.h
@@ -19,6 +19,9 @@
 
 #include <string>
 
+#undef major
+#undef minor
+
 class FString;
 
 struct VersionInfo
