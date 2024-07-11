--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2024-04-15 20:33:49 UTC
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -1989,7 +1989,7 @@ const gfx::VectorIcon& GetSharingHubVectorIcon() {
                  OmniboxFieldTrial::IsChromeRefreshActionChipIconsEnabled()
              ? omnibox::kShareWinChromeRefreshIcon
              : omnibox::kShareWinIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return OmniboxFieldTrial::IsChromeRefreshIconsEnabled() ||
                  OmniboxFieldTrial::IsChromeRefreshActionChipIconsEnabled()
              ? omnibox::kShareLinuxChromeRefreshIcon
