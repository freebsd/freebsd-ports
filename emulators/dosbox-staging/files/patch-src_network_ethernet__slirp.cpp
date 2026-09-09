--- src/network/ethernet_slirp.cpp.orig	2026-08-26 12:24:41 UTC
+++ src/network/ethernet_slirp.cpp
@@ -5,10 +5,6 @@
 #include <map>
 #include <stdexcept>
 
-#if defined(BSD)
-#include <sys/socket.h> // AF_INET
-#endif
-
 #include "dosbox.h"
 #include "dosbox_config.h"
 #include "utils/dynlib.h"
@@ -16,6 +12,10 @@
 #include "hardware/timer.h"
 #include "config/setup.h"
 #include "utils/string_utils.h"
+
+#if defined(BSD)
+#include <sys/socket.h> // AF_INET
+#endif
 
 /**
  * Platform specific libslirp shared library name
