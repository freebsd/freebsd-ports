--- chrome/browser/component_updater/wasm_tts_engine_component_installer.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/component_updater/wasm_tts_engine_component_installer.cc
@@ -8,7 +8,7 @@
 #include "base/functional/callback.h"
 #include "base/logging.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/accessibility/embedded_a11y_extension_loader.h"
 #include "chrome/common/extensions/extension_constants.h"
 #include "ui/accessibility/accessibility_features.h"
@@ -69,7 +69,7 @@ void WasmTtsEngineComponentInstallerPolicy::ComponentR
   VLOG(1) << "Component ready, version " << version.GetString() << " in "
           << install_dir.value();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (features::IsWasmTtsComponentUpdaterEnabled()) {
     EmbeddedA11yExtensionLoader::GetInstance()->Init();
     EmbeddedA11yExtensionLoader::GetInstance()->InstallExtensionWithIdAndPath(
