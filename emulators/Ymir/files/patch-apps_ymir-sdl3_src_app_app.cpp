--- apps/ymir-sdl3/src/app/app.cpp.orig	2025-07-20 22:35:27 UTC
+++ apps/ymir-sdl3/src/app/app.cpp
@@ -108,8 +108,8 @@
 #include <SDL3/SDL_filesystem.h>
 #include <SDL3/SDL_misc.h>
 
-#include <backends/imgui_impl_sdl3.h>
-#include <backends/imgui_impl_sdlrenderer3.h>
+#include <imgui_impl_sdl3.h>
+#include <imgui_impl_sdlrenderer3.h>
 
 #include <imgui.h>
 
@@ -1898,8 +1898,18 @@ void App::RunEmulator() {
                                                       actions::save_states::GetLoadStateAction(i),
                                                       actions::save_states::GetSaveStateAction(i));

+#if FMT_VERSION < 110000
+                                char timeStr[20];
+                                tm timeTm = util::to_local_time(state.timestamp);
+                                if (!strftime(timeStr, sizeof(timeStr), "%F %T", &timeTm)) {
+                                    memset(timeStr, 0, sizeof(timeStr));
+                                }
+#else
+                                tm timeStr = util::to_local_time(state.timestamp);
+#endif
+
                                 if (ImGui::MenuItem(
-                                        fmt::format("{}: {}", i, util::to_local_time(state.timestamp)).c_str(),
+                                        fmt::format("{}: {}", i, timeStr).c_str(),
                                         shortcut.c_str(), m_context.currSaveStateSlot == i, true)) {
                                     if (io.KeyShift) {
                                         SaveSaveStateSlot(i);
