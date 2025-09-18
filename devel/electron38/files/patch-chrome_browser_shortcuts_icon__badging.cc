--- chrome/browser/shortcuts/icon_badging.cc.orig	2024-06-18 21:43:23 UTC
+++ chrome/browser/shortcuts/icon_badging.cc
@@ -59,7 +59,7 @@ constexpr ShortcutSize kSizesNeededForShortcutCreation
 constexpr ShortcutSize kSizesNeededForShortcutCreation[] = {
     ShortcutSize::k16, ShortcutSize::k32, ShortcutSize::k128,
     ShortcutSize::k256, ShortcutSize::k512};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr ShortcutSize kSizesNeededForShortcutCreation[] = {ShortcutSize::k32,
                                                             ShortcutSize::k128};
 #elif BUILDFLAG(IS_WIN)
