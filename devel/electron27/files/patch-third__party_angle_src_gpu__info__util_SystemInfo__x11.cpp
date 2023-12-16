--- third_party/angle/src/gpu_info_util/SystemInfo_x11.cpp.orig	2022-02-23 20:48:53 UTC
+++ third_party/angle/src/gpu_info_util/SystemInfo_x11.cpp
@@ -8,6 +8,10 @@
 
 #include "gpu_info_util/SystemInfo_internal.h"
 
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#include <GL/glx.h>
+#include <GL/glxext.h>
+#endif
 #include <X11/Xlib.h>
 
 #include "common/debug.h"
@@ -18,8 +22,46 @@
 #    error SystemInfo_x11.cpp compiled without GPU_INFO_USE_X11
 #endif
 
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#define GLX_RENDERER_VENDOR_ID_MESA	0x8183
+#define GLX_RENDERER_DEVICE_ID_MESA	0x8184
+#endif
+
 namespace angle
 {
+
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+bool CollectMesaCardInfo(std::vector<GPUDeviceInfo> *devices)
+{
+    unsigned int vid[3], did[3];
+
+    Display *display = XOpenDisplay(NULL);
+    if (!display) {
+        return false;
+    }
+
+    PFNGLXQUERYRENDERERINTEGERMESAPROC queryInteger =
+        (PFNGLXQUERYRENDERERINTEGERMESAPROC) glXGetProcAddressARB((const GLubyte *)
+        "glXQueryRendererIntegerMESA");
+
+    if (!queryInteger)
+        return false;
+
+    bool vendor_ret =
+        queryInteger(display, 0, 0, GLX_RENDERER_VENDOR_ID_MESA, vid);
+    bool device_ret =
+        queryInteger(display, 0, 0, GLX_RENDERER_DEVICE_ID_MESA, did);
+
+    if (vendor_ret && device_ret) {
+        GPUDeviceInfo info;
+        info.vendorId = vid[0];
+        info.deviceId = did[0];
+        devices->push_back(info);
+    }
+
+    return true;
+}
+#endif
 
 bool GetNvidiaDriverVersionWithXNVCtrl(std::string *version)
 {
