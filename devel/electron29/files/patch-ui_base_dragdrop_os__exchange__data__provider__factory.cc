--- ui/base/dragdrop/os_exchange_data_provider_factory.cc.orig	2022-02-28 16:54:41 UTC
+++ ui/base/dragdrop/os_exchange_data_provider_factory.cc
@@ -7,7 +7,7 @@
 #include "base/notreached.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "ui/base/dragdrop/os_exchange_data_provider_factory_ozone.h"
 #include "ui/base/dragdrop/os_exchange_data_provider_non_backed.h"
 #elif BUILDFLAG(IS_APPLE)
@@ -21,7 +21,7 @@ namespace ui {
 // static
 std::unique_ptr<OSExchangeDataProvider>
 OSExchangeDataProviderFactory::CreateProvider() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The instance can be nullptr in tests that do not instantiate the platform,
   // or on platforms that do not implement specific drag'n'drop.  For them,
   // falling back to the Aura provider should be fine.
