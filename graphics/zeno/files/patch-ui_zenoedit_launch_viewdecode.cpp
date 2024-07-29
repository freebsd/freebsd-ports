--- ui/zenoedit/launch/viewdecode.cpp.orig	2024-04-23 11:14:37 UTC
+++ ui/zenoedit/launch/viewdecode.cpp
@@ -1,4 +1,4 @@
-#ifdef ZENO_MULTIPROCESS
+//#ifdef ZENO_MULTIPROCESS
 #include "viewdecode.h"
 #include "zenoapplication.h"
 #include <zenomodel/include/graphsmanagment.h>
@@ -335,4 +335,4 @@ void viewDecodeAppend(const char *buf, size_t n)
     zeno::log_debug("viewDecodeAppend n={}", n);
     viewDecodeData.append(buf, n);
 }
-#endif
+//#endif
