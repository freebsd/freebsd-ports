--- chrome/test/base/scoped_channel_override_posix.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/test/base/scoped_channel_override_posix.cc
@@ -43,7 +43,7 @@ std::string GetVersionExtra(ScopedChannelOverride::Cha
       return "beta";
     case ScopedChannelOverride::Channel::kDev:
       return "unstable";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ScopedChannelOverride::Channel::kCanary:
       return "canary";
 #endif  // BUILDFLAG(IS_LINUX)
