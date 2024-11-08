--- ui/base/accelerators/accelerator_unittest.cc.orig	2024-10-18 12:35:12 UTC
+++ ui/base/accelerators/accelerator_unittest.cc
@@ -59,6 +59,9 @@ TEST(AcceleratorTest, MAYBE_GetShortcutText) {
 #if BUILDFLAG(IS_MAC)
     {VKEY_T, EF_COMMAND_DOWN | EF_CONTROL_DOWN, nullptr, u"⌃⌘T"},
 #endif
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
+    {VKEY_T, EF_COMMAND_DOWN | EF_CONTROL_DOWN, u"Super+Ctrl+T", nullptr},
+#endif
   };
 
   for (const auto& key : keys) {
