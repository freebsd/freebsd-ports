--- src/unix/fcitx/fcitx_mozc.cc.orig	2016-05-14 21:54:58.149355000 +0900
+++ src/unix/fcitx/fcitx_mozc.cc	2016-05-14 21:54:58.170065000 +0900
@@ -440,6 +440,8 @@
 boolean ToolMenuAction(struct _FcitxUIMenu *menu, int index)
 {
     string args;
+    size_t pid = 0;
+
     switch(index) {
         case 0:
             args = "--mode=config_dialog";
@@ -460,7 +462,8 @@
             args = "--mode=about_dialog";
             break;
     }
-    mozc::Process::SpawnMozcProcess("mozc_tool", args);
+    
+    mozc::Process::SpawnProcess(mozc::FileUtil::JoinPath(mozc::SystemUtil::GetToolPath(), "mozc_tool"), args, &pid);
     return true;
 }
 
