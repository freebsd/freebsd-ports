--- ui/zenoedit/launch/offlinemain.cpp.orig	2024-04-26 16:52:52 UTC
+++ ui/zenoedit/launch/offlinemain.cpp
@@ -14,6 +14,7 @@
 #include <zeno/extra/assetDir.h>
 #include "util/apphelper.h"
 #include "launch/ztcpserver.h"
+#include "zenoapplication.h"
 
 int offline_main(const QCoreApplication& app);
 int offline_main(const QCoreApplication& app) {
