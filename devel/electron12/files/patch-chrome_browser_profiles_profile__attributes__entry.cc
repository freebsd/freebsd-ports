--- chrome/browser/profiles/profile_attributes_entry.cc.orig	2021-04-14 01:08:40 UTC
+++ chrome/browser/profiles/profile_attributes_entry.cc
@@ -159,7 +159,7 @@ void ProfileAttributesEntry::Initialize(ProfileInfoCac
   if (is_force_signin_enabled_) {
     if (!IsAuthenticated())
       is_force_signin_profile_locked_ = true;
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_WIN)
   } else if (IsSigninRequired()) {
     // Profiles that require signin in the absence of an enterprise policy are
