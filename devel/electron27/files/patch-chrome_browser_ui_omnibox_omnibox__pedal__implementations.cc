--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2023-10-19 19:58:07 UTC
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -1961,7 +1961,7 @@ const gfx::VectorIcon& GetSharingHubVectorIcon() {
                  OmniboxFieldTrial::IsChromeRefreshActionChipIconsEnabled()
              ? omnibox::kShareWinChromeRefreshIcon
              : omnibox::kShareWinIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return OmniboxFieldTrial::IsChromeRefreshIconsEnabled() ||
                  OmniboxFieldTrial::IsChromeRefreshActionChipIconsEnabled()
              ? omnibox::kShareLinuxChromeRefreshIcon
