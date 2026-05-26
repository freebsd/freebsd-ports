--- src/framework/ui/uimodule.cpp.orig	2026-05-18 12:36:14 UTC
+++ src/framework/ui/uimodule.cpp
@@ -87,8 +87,8 @@ void UiModule::registerExports()
     m_platformTheme = std::make_shared<LinuxPlatformTheme>();
     m_windowsController = std::make_shared<WindowsController>();
     #else
-    m_windowsController = std::make_shared<WindowsController>();
     m_platformTheme = std::make_shared<StubPlatformTheme>();
+    m_windowsController = std::make_shared<WindowsController>();
     #endif
 
     ioc()->registerExport<IUiConfiguration>(moduleName(), m_configuration);
