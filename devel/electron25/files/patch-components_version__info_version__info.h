--- components/version_info/version_info.h.orig	2023-05-25 00:41:54 UTC
+++ components/version_info/version_info.h
@@ -7,10 +7,6 @@
 
 #include <string>
 
-#include "base/notreached.h"
-#include "base/sanitizer_buildflags.h"
-#include "build/branding_buildflags.h"
-#include "build/build_config.h"
 #include "components/version_info/channel.h"
 #include "components/version_info/version_info_values.h"
 
@@ -20,6 +16,10 @@ class Version;
 
 namespace version_info {
 
+// Returns the product name and version information for the User-Agent header,
+// in the format: Chrome/<major_version>.<minor_version>.<build>.<patch>.
+const std::string& GetProductNameAndVersionForUserAgent();
+
 // Returns the product name and reduced version information for the User-Agent
 // header, in the format: Chrome/<major_version>.0.build_version.0, where
 // `build_version` is a frozen BUILD number.
@@ -27,21 +27,11 @@ const std::string GetProductNameAndVersionForReducedUs
     const std::string& build_version);
 
 // Returns the product name, e.g. "Chromium" or "Google Chrome".
-constexpr std::string GetProductName() {
-  return PRODUCT_NAME;
-}
+std::string GetProductName();
 
 // Returns the version number, e.g. "6.0.490.1".
-constexpr std::string GetVersionNumber() {
-  return PRODUCT_VERSION;
-}
+std::string GetVersionNumber();
 
-// Returns the product name and version information for the User-Agent header,
-// in the format: Chrome/<major_version>.<minor_version>.<build>.<patch>.
-constexpr std::string GetProductNameAndVersionForUserAgent() {
-  return "Chrome/" + GetVersionNumber();
-}
-
 // Returns the major component (aka the milestone) of the version as an int,
 // e.g. 6 when the version is "6.0.490.1".
 int GetMajorVersionNumberAsInt();
@@ -53,89 +43,22 @@ std::string GetMajorVersionNumber();
 const base::Version& GetVersion();
 
 // Returns a version control specific identifier of this release.
-constexpr std::string GetLastChange() {
-  return LAST_CHANGE;
-}
+std::string GetLastChange();
 
 // Returns whether this is an "official" release of the current version, i.e.
 // whether knowing GetVersionNumber() is enough to completely determine what
 // GetLastChange() is.
-constexpr bool IsOfficialBuild() {
-  return IS_OFFICIAL_BUILD;
-}
+bool IsOfficialBuild();
 
 // Returns the OS type, e.g. "Windows", "Linux", "FreeBSD", ...
-constexpr std::string GetOSType() {
-#if BUILDFLAG(IS_WIN)
-  return "Windows";
-#elif BUILDFLAG(IS_IOS)
-  return "iOS";
-#elif BUILDFLAG(IS_MAC)
-  return "Mac OS X";
-#elif BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(GOOGLE_CHROME_BRANDING)
-  return "ChromeOS";
-#else
-  return "ChromiumOS";
-#endif
-#elif BUILDFLAG(IS_ANDROID)
-  return "Android";
-#elif BUILDFLAG(IS_LINUX)
-  return "Linux";
-#elif BUILDFLAG(IS_FREEBSD)
-  return "FreeBSD";
-#elif BUILDFLAG(IS_OPENBSD)
-  return "OpenBSD";
-#elif BUILDFLAG(IS_SOLARIS)
-  return "Solaris";
-#elif BUILDFLAG(IS_FUCHSIA)
-  return "Fuchsia";
-#else
-  return "Unknown";
-#endif
-}
+std::string GetOSType();
 
 // Returns a string equivalent of |channel|, independent of whether the build
 // is branded or not and without any additional modifiers.
-constexpr std::string GetChannelString(Channel channel) {
-  switch (channel) {
-    case Channel::STABLE:
-      return "stable";
-    case Channel::BETA:
-      return "beta";
-    case Channel::DEV:
-      return "dev";
-    case Channel::CANARY:
-      return "canary";
-    case Channel::UNKNOWN:
-      return "unknown";
-  }
-  NOTREACHED_NORETURN();
-}
+std::string GetChannelString(Channel channel);
 
 // Returns a list of sanitizers enabled in this build.
-constexpr std::string GetSanitizerList() {
-  return ""
-#if defined(ADDRESS_SANITIZER)
-         "address "
-#endif
-#if BUILDFLAG(IS_HWASAN)
-         "hwaddress "
-#endif
-#if defined(LEAK_SANITIZER)
-         "leak "
-#endif
-#if defined(MEMORY_SANITIZER)
-         "memory "
-#endif
-#if defined(THREAD_SANITIZER)
-         "thread "
-#endif
-#if defined(UNDEFINED_SANITIZER)
-         "undefined "
-#endif
-      ;
-}
+std::string GetSanitizerList();
 
 }  // namespace version_info
 
