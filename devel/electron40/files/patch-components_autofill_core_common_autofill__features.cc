--- components/autofill/core/common/autofill_features.cc.orig	2026-01-07 00:52:53 UTC
+++ components/autofill/core/common/autofill_features.cc
@@ -10,7 +10,7 @@ constexpr bool IS_AUTOFILL_AI_PLATFORM = BUILDFLAG(IS_
 
 namespace {
 constexpr bool IS_AUTOFILL_AI_PLATFORM = BUILDFLAG(IS_CHROMEOS) ||
-                                         BUILDFLAG(IS_LINUX) ||
+                                         BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) ||
                                          BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN);
 constexpr bool IS_WALLET_PASSES_SUPPORTED_PLATFORM = !BUILDFLAG(IS_IOS);
 }
