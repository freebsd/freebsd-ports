--- net/dns/host_resolver_manager.cc.orig	2022-09-24 10:57:32 UTC
+++ net/dns/host_resolver_manager.cc
@@ -3126,7 +3126,7 @@ HostResolverManager::HostResolverManager(
   }
   if (system_dns_config_notifier_)
     system_dns_config_notifier_->AddObserver(this);
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_OPENBSD) && \
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD) && \
     !BUILDFLAG(IS_ANDROID)
   EnsureDnsReloaderInit();
 #endif
