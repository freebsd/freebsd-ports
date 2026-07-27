--- apps/ymir-sdl3/src/app/services/update_checker_service.cpp.orig	2026-07-27 12:58:00 UTC
+++ apps/ymir-sdl3/src/app/services/update_checker_service.cpp
@@ -131,15 +131,13 @@ void UpdateCheckerService::ThreadLoop(SharedContext &c
                 // Stable release couldn't be retrieved or isn't newer than the current version.
                 // Check if nightly is an update.
                 if (!context.targetUpdate) {
-                    if (semver::detail::compare_parsed(nightlyResult.updateInfo.version, currVersion,
-                                                       semver::version_compare_option::exclude_prerelease) > 0) {
+                    if (semver::detail::compare_parsed(nightlyResult.updateInfo.version, currVersion) > 0) {
                         return true;
                     }
 
                     if constexpr (ymir::version::is_nightly_build) {
                         // Current version is a nightly build
-                        if (semver::detail::compare_parsed(nightlyResult.updateInfo.version, currVersion,
-                                                           semver::version_compare_option::exclude_prerelease) < 0) {
+                        if (semver::detail::compare_parsed(nightlyResult.updateInfo.version, currVersion) < 0) {
                             return false;
                         }
 
