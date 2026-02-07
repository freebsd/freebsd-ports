--- ./port.h.orig	2025-02-16 11:47:28 UTC
+++ ./port.h
@@ -32,6 +32,7 @@
 #include <netdb.h>
 #endif
 
+#include <netinet/in.h>
 #include <gensio/gensio.h>
 
 #include "gbuf.h"
