--- bundled_deps/avrdude/avrdude/libavrdude.h.orig	2024-12-20 11:54:34 UTC
+++ bundled_deps/avrdude/avrdude/libavrdude.h
@@ -950,6 +950,8 @@ int read_config_builtin();
 // Header file for alloca()
 #if defined(WIN32NATIVE)
 #  include <malloc.h>
+#elif defined __FreeBSD__
+#  include <stdlib.h>
 #else
 #  include <alloca.h>
 #endif
