--- src/engine/tlssocket.h.orig	2015-02-04 03:35:52.000000000 +0100
+++ src/engine/tlssocket.h	2015-02-04 03:36:18.000000000 +0100
@@ -1,6 +1,7 @@
 #ifndef __TLSSOCKET_H__
 #define __TLSSOCKET_H__
 
+#include <errno.h>
 #include <gnutls/gnutls.h>
 #include "backend.h"
 #include "socket.h"
