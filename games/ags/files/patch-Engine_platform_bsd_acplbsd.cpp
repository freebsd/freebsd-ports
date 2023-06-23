--- Engine/platform/bsd/acplbsd.cpp.orig	2023-06-23 17:18:33 UTC
+++ Engine/platform/bsd/acplbsd.cpp
@@ -19,7 +19,7 @@
 // *************** FREEBSD DRIVER ***************
 
 #include "platform/base/agsplatformdriver.h"
-#include "platform/base/agsplatform_unix.h"
+#include "platform/base/agsplatform_xdg_unix.h"
 
 struct AGSFreeBSD : AGSPlatformXDGUnix {
     eScriptSystemOSID GetSystemOSID() override;
