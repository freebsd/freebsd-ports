--- src/VBox/Additions/common/VBoxService/VBoxService.cpp.orig	2010-05-18 20:10:47.000000000 +0200
+++ src/VBox/Additions/common/VBoxService/VBoxService.cpp	2010-05-19 21:47:17.000000000 +0200
@@ -28,6 +28,9 @@
 #ifndef RT_OS_WINDOWS
 # include <signal.h>
 #endif
+#ifdef RT_OS_FREEBSD
+# include <pthread.h>
+#endif 
 
 #include "product-generated.h"
 #include <iprt/asm.h>
