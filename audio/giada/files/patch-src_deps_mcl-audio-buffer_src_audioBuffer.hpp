-- add missing include stdio.h for printf

--- src/deps/mcl-audio-buffer/src/audioBuffer.hpp.orig	2026-05-21 16:24:10 UTC
+++ src/deps/mcl-audio-buffer/src/audioBuffer.hpp
@@ -34,6 +34,8 @@
 #include <memory>
 #include <utility>
 
+#include <stdio.h>
+
 namespace mcl
 {
 /* AudioBuffer
@@ -482,4 +484,4 @@ class AudioBuffer (private)
 };
 } // namespace mcl
 
-#endif
\ No newline at end of file
+#endif
