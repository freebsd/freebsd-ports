--- ./expoblending/manager/actionthread.cpp.orig	2010-02-01 01:17:40.000000000 +1000
+++ ./expoblending/manager/actionthread.cpp	2010-02-03 01:12:30.759423612 +1000
@@ -53,6 +53,10 @@
 #include "kpwriteimage.h"
 #include "pluginsversion.h"
 
+#if defined(__FreeBSD__)
+#define log2f(x) (logf((x)) / logf(2))
+#endif
+
 namespace KIPIExpoBlendingPlugin
 {
 
