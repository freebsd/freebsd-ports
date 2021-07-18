--- ui/events/ozone/keyboard_hook_ozone.cc.orig	2021-01-07 00:37:28 UTC
+++ ui/events/ozone/keyboard_hook_ozone.cc
@@ -29,7 +29,7 @@ bool KeyboardHookOzone::RegisterHook() {
   return true;
 }
 
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 // static
 std::unique_ptr<KeyboardHook> KeyboardHook::CreateModifierKeyboardHook(
     base::Optional<base::flat_set<DomCode>> dom_codes,
