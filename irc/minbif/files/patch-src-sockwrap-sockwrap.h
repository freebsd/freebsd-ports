--- src/sockwrap/sockwrap.h.orig	2010-04-21 19:04:39.000000000 +0200
+++ src/sockwrap/sockwrap.h	2010-04-21 19:05:00.000000000 +0200
@@ -24,6 +24,11 @@
 #include "core/config.h"
 #include "core/callback.h"
 
+#if defined(__FreeBSD__) || defined(__FreeBSD)
+#include <sys/types.h>
+#include <sys/socket.h>
+#endif
+
 #ifndef PF_SOCKWRAP_H
 #define PF_SOCKWRAP_H
 
