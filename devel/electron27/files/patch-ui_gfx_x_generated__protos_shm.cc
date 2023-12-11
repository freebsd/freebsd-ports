--- ui/gfx/x/generated_protos/shm.cc.orig	2022-02-28 16:54:41 UTC
+++ ui/gfx/x/generated_protos/shm.cc
@@ -44,6 +44,8 @@
 #include <xcb/xcb.h>
 #include <xcb/xcbext.h>
 
+#include <unistd.h>
+
 #include "base/logging.h"
 #include "base/posix/eintr_wrapper.h"
 #include "ui/gfx/x/xproto_internal.h"
