--- ui/gfx/x/generated_protos/dri3.cc.orig	2021-09-14 01:52:23 UTC
+++ ui/gfx/x/generated_protos/dri3.cc
@@ -43,6 +43,8 @@
 #include <xcb/xcb.h>
 #include <xcb/xcbext.h>
 
+#include <unistd.h>
+
 #include "base/logging.h"
 #include "base/posix/eintr_wrapper.h"
 #include "ui/gfx/x/xproto_internal.h"
