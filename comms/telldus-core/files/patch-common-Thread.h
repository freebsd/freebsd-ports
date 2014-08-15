--- common/Thread.h
+++ common/Thread.h
@@ -13,6 +13,9 @@
 #define TELLDUS_CORE_COMMON_THREAD_H_
 
 #include <string>
+#ifdef __FreeBSD__
+#include <pthread.h>
+#endif
 #include "common/Mutex.h"
 
 namespace TelldusCore {
