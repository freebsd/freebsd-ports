--- src/platform/C4FileMonitor.cpp.orig	2022-01-02 18:07:10 UTC
+++ src/platform/C4FileMonitor.cpp
@@ -21,6 +21,8 @@
 
 #include "game/C4Application.h"
 
+#undef HAVE_SYS_INOTIFY_H
+
 #ifdef HAVE_SYS_INOTIFY_H
 #include <sys/inotify.h>
 
