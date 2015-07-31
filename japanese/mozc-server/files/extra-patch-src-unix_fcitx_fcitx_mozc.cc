--- src/unix/fcitx/fcitx_mozc.cc.orig	2015-02-19 10:48:37.000000000 +0900
+++ src/unix/fcitx/fcitx_mozc.cc	2015-02-19 10:54:04.000000000 +0900
@@ -439,6 +439,8 @@
 boolean ToolMenuAction(struct _FcitxUIMenu *menu, int index)
 {
     string args;
+    size_t pid = 0;
+
     switch(index) {
         case 0:
             args = "--mode=config_dialog";
@@ -459,7 +461,8 @@
             args = "--mode=about_dialog";
             break;
     }
-    mozc::Process::SpawnMozcProcess("mozc_tool", args);
+    
+    mozc::Process::SpawnProcess(mozc::FileUtil::JoinPath(mozc::SystemUtil::GetToolPath(), "mozc_tool"), args, &pid);
     return true;
 }
 
