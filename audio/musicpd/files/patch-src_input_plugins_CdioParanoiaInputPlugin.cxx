--- src/input/plugins/CdioParanoiaInputPlugin.cxx.orig	2025-03-16 11:40:07 UTC
+++ src/input/plugins/CdioParanoiaInputPlugin.cxx
@@ -5,6 +5,8 @@
  * CD-Audio handling (requires libcdio_paranoia)
  */
 
+#include <cstddef>
+
 #include "CdioParanoiaInputPlugin.hxx"
 #include "lib/cdio/Paranoia.hxx"
 #include "lib/fmt/RuntimeError.hxx"
