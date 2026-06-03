--- components/dbus/xdg/file_transfer_portal.cc.orig	2026-03-13 16:54:03 UTC
+++ components/dbus/xdg/file_transfer_portal.cc
@@ -28,6 +28,10 @@
 #include "dbus/object_path.h"
 #include "dbus/object_proxy.h"
 
+#if BUILDFLAG(IS_BSD) && !defined(O_PATH)
+#define O_PATH 0
+#endif
+
 namespace dbus_xdg {
 
 BASE_FEATURE(kXdgFileTransferPortal, base::FEATURE_DISABLED_BY_DEFAULT);
