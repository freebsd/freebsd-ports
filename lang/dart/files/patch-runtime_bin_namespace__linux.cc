Use the large-file names from platform/largefile.h (series 0006).
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/namespace_linux.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/namespace_linux.cc
@@ -11,6 +11,7 @@
 #include <fcntl.h>
 
 #include "bin/file.h"
+#include "platform/largefile.h"
 #include "platform/signal_blocker.h"
 #include "platform/text_buffer.h"
 
