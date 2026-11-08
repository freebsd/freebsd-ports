-- Avoid macro conflicts with system macros (major, minor, patch) on BSD systems
-- by undefining them before the Version class definition.

--- NeuralAudio/deps/NeuralAmpModelerCore/NAM/get_dsp.h.orig	2026-09-23 18:46:14 UTC
+++ NeuralAudio/deps/NeuralAmpModelerCore/NAM/get_dsp.h
@@ -23,6 +23,10 @@ class IVersionSupportChecker (public)
   virtual Supported support(const std::string& version) const = 0;
 };
 
+// Avoid conflicts with system macros on BSD systems
+#undef major
+#undef minor
+#undef patch
 class Version
 {
 public:
