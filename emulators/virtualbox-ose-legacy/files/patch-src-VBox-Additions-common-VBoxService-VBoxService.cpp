--- src/VBox/Additions/common/VBoxService/VBoxService.cpp.orig	2010-04-24 12:08:30.000000000 +0200
+++ src/VBox/Additions/common/VBoxService/VBoxService.cpp	2010-04-24 12:10:35.000000000 +0200
@@ -32,6 +32,9 @@
 #ifndef RT_OS_WINDOWS
 # include <signal.h>
 #endif
+#ifdef RT_OS_FREEBSD
+# include <pthread.h>
+#endif 
 
 #include "product-generated.h"
 #include <iprt/asm.h>
