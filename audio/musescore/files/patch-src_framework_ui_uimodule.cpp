--- src/framework/ui/uimodule.cpp.orig	2025-12-01 12:36:11 UTC
+++ src/framework/ui/uimodule.cpp
@@ -49,6 +49,7 @@
 #include "view/mainwindowbridge.h"
 #else
 #include "internal/platform/stub/stubplatformtheme.h"
+#include "internal/windowscontroller.h"
 #include "view/mainwindowbridge.h"
 #endif
 
@@ -109,6 +110,7 @@ void UiModule::registerExports()
     m_windowsController = std::make_shared<WindowsController>();
     #else
     m_platformTheme = std::make_shared<StubPlatformTheme>();
+    m_windowsController = std::make_shared<WindowsController>();
     #endif
 
     ioc()->registerExport<IUiConfiguration>(moduleName(), m_configuration);
