--- components/device_signals/test/signals_contract.cc.orig	2022-11-30 08:12:58 UTC
+++ components/device_signals/test/signals_contract.cc
@@ -164,7 +164,7 @@ GetSignalsContract() {
       base::BindRepeating(VerifyUnset, names::kSecureBootEnabled);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUIDLFLAG(IS_BSD)
   contract[names::kAllowScreenLock] =
       base::BindRepeating(VerifyUnset, names::kAllowScreenLock);
   contract[names::kImei] = base::BindRepeating(VerifyUnset, names::kImei);
