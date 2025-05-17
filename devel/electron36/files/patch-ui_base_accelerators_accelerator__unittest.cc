--- ui/base/accelerators/accelerator_unittest.cc.orig	2025-03-24 20:50:14 UTC
+++ ui/base/accelerators/accelerator_unittest.cc
@@ -56,7 +56,7 @@ TEST(AcceleratorTest, MAYBE_GetShortcutText) {
 #if BUILDFLAG(IS_MAC)
       {VKEY_T, EF_COMMAND_DOWN | EF_CONTROL_DOWN, nullptr, u"⌃⌘T"},
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {VKEY_T, EF_COMMAND_DOWN | EF_CONTROL_DOWN, u"Super+Ctrl+T", nullptr},
 #endif
   };
