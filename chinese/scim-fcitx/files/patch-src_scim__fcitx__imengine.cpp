--- src/scim_fcitx_imengine.cpp.orig	2019-04-09 08:12:58 UTC
+++ src/scim_fcitx_imengine.cpp
@@ -35,6 +35,10 @@
 #define Uses_SCIM_CONFIG_BASE
 #define Uses_SCIM_CONFIG_PATH
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
+#include <cstring>
 #include <scim.h>
 #include "scim_fcitx_imengine.h"
 #include "main.h"
