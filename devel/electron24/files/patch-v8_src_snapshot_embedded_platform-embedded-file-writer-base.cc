--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc.orig	2023-02-01 18:45:24 UTC
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc
@@ -142,6 +142,8 @@ EmbeddedTargetOs ToEmbeddedTargetOs(const char* s) {
     return EmbeddedTargetOs::kWin;
   } else if (string == "starboard") {
     return EmbeddedTargetOs::kStarboard;
+  } else if (string == "openbsd") {
+    return EmbeddedTargetOs::kOpenBSD;
   } else {
     return EmbeddedTargetOs::kGeneric;
   }
