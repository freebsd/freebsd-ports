--- src/avrdude/libavrdude.h.orig	2020-03-21 10:55:51 UTC
+++ src/avrdude/libavrdude.h
@@ -950,6 +950,8 @@ int read_config_builtin();
 // Header file for alloca()
 #if defined(WIN32NATIVE)
 #  include <malloc.h>
+#elif defined __FreeBSD__
+#  include <stdlib.h>
 #else
 #  include <alloca.h>
 #endif
