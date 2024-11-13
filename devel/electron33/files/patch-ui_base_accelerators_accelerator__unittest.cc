--- ui/base/accelerators/accelerator_unittest.cc.orig	2024-11-11 11:19:16 UTC
+++ ui/base/accelerators/accelerator_unittest.cc
@@ -59,7 +59,7 @@ TEST(AcceleratorTest, MAYBE_GetShortcutText) {
 #if BUILDFLAG(IS_MAC)
     {VKEY_T, EF_COMMAND_DOWN | EF_CONTROL_DOWN, nullptr, u"⌃⌘T"},
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {VKEY_T, EF_COMMAND_DOWN | EF_CONTROL_DOWN, u"Super+Ctrl+T", nullptr},
 #endif
   };
