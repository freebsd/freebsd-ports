--- ash/display/mirror_window_controller.cc.orig	2022-05-19 05:17:32 UTC
+++ ash/display/mirror_window_controller.cc
@@ -296,7 +296,11 @@ void MirrorWindowController::UpdateWindow(
                          return info.id() == iter->first;
                        }) == display_info_list.end()) {
         CloseAndDeleteHost(iter->second, true);
+#if defined(__llvm__)
+        mirroring_host_info_map_.erase(iter++);
+#else
         iter = mirroring_host_info_map_.erase(iter);
+#endif
       } else {
         ++iter;
       }
