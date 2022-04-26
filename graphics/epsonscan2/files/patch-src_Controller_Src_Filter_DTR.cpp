--- src/Controller/Src/Filter/DTR.cpp.orig	2021-11-25 00:56:57 UTC
+++ src/Controller/Src/Filter/DTR.cpp
@@ -26,6 +26,9 @@
 #include <utils/ESFile.h>
 #include <ES2Command/ES2CommandAPI.h>
 #include <math.h>
+#if __FreeBSD__
+#include <sys/wait.h>
+#endif
 namespace epsonscan
 {
 static const int kMaxBuf = 256;
@@ -409,7 +412,7 @@ ESNumber CustomSkipLevelAsPercent(ESNumber inLevel)
         dtrExecCommand << " ";
         dtrExecCommand << "0";
         dtrExecCommand << " ";
-        dtrExecCommand << (keyMgr->GetValueInt(kSDIAutoColorPixelTypeKey) == kSDIAutoColorPixelTypeAuto) ? 1 : 0;
+        dtrExecCommand << ((keyMgr->GetValueInt(kSDIAutoColorPixelTypeKey) == kSDIAutoColorPixelTypeAuto) ? 1 : 0);
         dtrExecCommand << " ";
         dtrExecCommand << keyMgr->GetValueInt(kSDIAutoColorPixelLevelKey);
         SDI_TRACE_LOG("dtrExecCommand = %s", dtrExecCommand.str().c_str());
