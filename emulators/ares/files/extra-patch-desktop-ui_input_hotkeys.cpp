--- desktop-ui/input/hotkeys.cpp.orig	2024-11-22 20:50:39 UTC
+++ desktop-ui/input/hotkeys.cpp
@@ -149,6 +149,9 @@ auto InputManager::pollHotkeys() -> void {
   }
 
   for(auto& hotkey : hotkeys) {
+    if(emulator && !hotkey.name.equals("Pause Emulation") && !program.paused) {
+      continue;
+    }
     auto state = hotkey.value();
     if(hotkey.state == 0 && state == 1 && hotkey.press) hotkey.press();
     if(hotkey.state == 1 && state == 0 && hotkey.release) hotkey.release();
