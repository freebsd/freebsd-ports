--- components/feature_engagement/public/event_constants.h.orig	2019-03-15 06:37:14 UTC
+++ components/feature_engagement/public/event_constants.h
@@ -42,7 +42,7 @@ extern const char kIncognitoWindowOpened[];
 extern const char kIncognitoWindowSessionTimeMet[];
 #endif  // BUILDFLAG(ENABLE_DESKTOP_IN_PRODUCT_HELP)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS) || defined(OS_BSD)
 // This event is included in the deferred onboarding events for the New Tab
 // described above, but it is also used on iOS, so it must be compiled
 // separately.
@@ -50,7 +50,7 @@ extern const char kIncognitoWindowSessionTimeMet[];
 // The user has explicitly opened a new tab via an entry point from inside of
 // Chrome.
 extern const char kNewTabOpened[];
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS) || defined(OS_BSD)
 
 #if defined(OS_IOS)
 // The user has opened Chrome (cold start or from background).
