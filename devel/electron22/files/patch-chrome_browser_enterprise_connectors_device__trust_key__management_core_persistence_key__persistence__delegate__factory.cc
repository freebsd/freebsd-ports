--- chrome/browser/enterprise/connectors/device_trust/key_management/core/persistence/key_persistence_delegate_factory.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/enterprise/connectors/device_trust/key_management/core/persistence/key_persistence_delegate_factory.cc
@@ -13,7 +13,7 @@
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/core/persistence/win_key_persistence_delegate.h"
 #elif BUILDFLAG(IS_MAC)
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/core/persistence/mac_key_persistence_delegate.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/core/persistence/linux_key_persistence_delegate.h"
 #endif
 
@@ -44,7 +44,7 @@ KeyPersistenceDelegateFactory::CreateKeyPersistenceDel
   return std::make_unique<WinKeyPersistenceDelegate>();
 #elif BUILDFLAG(IS_MAC)
   return std::make_unique<MacKeyPersistenceDelegate>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<LinuxKeyPersistenceDelegate>();
 #else
   NOTREACHED();
