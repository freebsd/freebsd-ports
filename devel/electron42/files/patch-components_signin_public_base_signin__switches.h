--- components/signin/public/base/signin_switches.h.orig	2026-04-28 21:06:17 UTC
+++ components/signin/public/base/signin_switches.h
@@ -62,7 +62,7 @@ base::TimeDelta GetAvatarSyncPromoFeatureMinimumCookeA
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 base::TimeDelta GetAvatarSyncPromoFeatureMinimumCookeAgeParam();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A HaTS survey flag for the survey to gather user feedback before any changes
 // to the FRE as part of Chrome Desktop FRE Refresh project.
 //
@@ -113,7 +113,7 @@ BASE_DECLARE_FEATURE(kChromeAndroidIdentitySurveyBookm
 BASE_DECLARE_FEATURE(kChromeAndroidIdentitySurveyBookmarkPromo);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables surveys to measure the effectiveness of the identity model.
 // These surveys would be displayed after interactions such as signin, profile
 // switching, etc. Please keep sorted alphabetically.
@@ -190,7 +190,7 @@ BASE_DECLARE_FEATURE_PARAM(
 // LINT.ThenChange(//chrome/browser/signin/signin_hats_util.cc)
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Controls the duration for which the launch of an identity survey is delayed.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kChromeIdentitySurveyLaunchWithDelay);
@@ -199,7 +199,7 @@ BASE_DECLARE_FEATURE_PARAM(base::TimeDelta,
                            kChromeIdentitySurveyLaunchWithDelayDuration);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If enabled, disables feedback for U18 users on desktop platforms.
 // The iOS version is kDisableU18FeedbackIos flag.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
@@ -322,7 +322,7 @@ extern const base::FeatureParam<base::TimeDelta>
     kPolicyDisclaimerRegistrationRetryDelay;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This feature controls running visually refreshed first run and profile
 // creation flows for users outside of the search engine choice regions. To
 // enable the refresh in search engine choice screen regions,
@@ -376,7 +376,7 @@ extern const base::FeatureParam<FirstRunDesktopSignInP
     kFirstRunDesktopSignInPromoVariation;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A HaTS survey flag for the survey to gather user feedback after the changes
 // introduced with `kFirstRunDesktopRefresh`.
 //
@@ -386,7 +386,7 @@ BASE_DECLARE_FEATURE(kFirstRunDesktopRefreshSurvey);
 BASE_DECLARE_FEATURE(kFirstRunDesktopRefreshSurvey);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // It enables the first run revamp (introduce new UIs and additional effects).
 // This feature is no-op if `kFirstRunDesktopRefresh` is disabled.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
@@ -452,7 +452,7 @@ BASE_DECLARE_FEATURE(kNonDefaultGaiaOriginCheck);
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kNonDefaultGaiaOriginCheck);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Experimenting with a button to all profiles from the profile picker.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kOpenAllProfilesFromProfilePickerExperiment);
@@ -461,7 +461,7 @@ extern const base::FeatureParam<int>
     kMaxProfilesCountToShowOpenAllButtonInProfilePicker;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Add new entry points for uploading passwords to account storage and update
 // existing ones.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
@@ -547,7 +547,7 @@ extern const base::FeatureParam<int> kContextualSignin
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 extern const base::FeatureParam<int> kContextualSigninPromoDismissedThreshold;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Uses the Material Next theme for the signin promo.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kSignInPromoMaterialNextUI);
@@ -602,7 +602,7 @@ BASE_DECLARE_FEATURE(kSupportAddSessionEmailPrefill);
 BASE_DECLARE_FEATURE(kSupportAddSessionEmailPrefill);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Kill switch for displaying sign-in errors in the profile picker.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kSupportErrorsInProfilePicker);
