--- src/ime.h.orig	2019-04-09 08:16:46 UTC
+++ src/ime.h
@@ -2,6 +2,9 @@
 #define _IME_H
 
 #include "xim.h"
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 
 #include "scim_fcitx_imengine.h"
 
