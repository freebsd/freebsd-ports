--- third_party/pdfium/core/fxge/fx_ge_linux.cpp.orig	2021-07-15 19:15:50 UTC
+++ third_party/pdfium/core/fxge/fx_ge_linux.cpp
@@ -17,7 +17,7 @@
 #include "third_party/base/check.h"
 #include "third_party/base/stl_util.h"
 
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ASMJS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ASMJS) && !defined(OS_BSD)
 #error "Included on the wrong platform"
 #endif
 
@@ -166,10 +166,16 @@ class CLinuxPlatform : public CFX_GEModule::PlatformIf
   std::unique_ptr<SystemFontInfoIface> CreateDefaultSystemFontInfo() override {
     auto pInfo = std::make_unique<CFX_LinuxFontInfo>();
     if (!pInfo->ParseFontCfg(CFX_GEModule::Get()->GetUserFontPaths())) {
+#if defined(OS_BSD)
+      pInfo->AddPath("/usr/local/share/fonts");
+      pInfo->AddPath("/usr/local/share/X11/fonts/Type1");
+      pInfo->AddPath("/usr/local/share/X11/fonts/TTF");
+#else
       pInfo->AddPath("/usr/share/fonts");
       pInfo->AddPath("/usr/share/X11/fonts/Type1");
       pInfo->AddPath("/usr/share/X11/fonts/TTF");
-      pInfo->AddPath("/usr/local/share/fonts");
+      pInfo->AddPath("/usr/local/share/fonts")
+#endif
     }
     return pInfo;
   }
