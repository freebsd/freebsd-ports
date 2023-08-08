--- src/editor/editorapp.h.orig	2016-05-01 20:07:33 UTC
+++ src/editor/editorapp.h
@@ -122,12 +122,12 @@ class EditorApp : public Singleton < EditorApp > { (pr
 private:
     bool running_;
 
-    std::auto_ptr<Screen> screen_;
-    std::auto_ptr<System> system_;
+    std::unique_ptr<Screen> screen_;
+    std::unique_ptr<System> system_;
     /*! A structure to hold general application informations.*/
-    std::auto_ptr<AppContext> context_;
+    std::unique_ptr<AppContext> context_;
     /*! Controls the game logic. */
-    std::auto_ptr<GameController> game_ctlr_;
+    std::unique_ptr<GameController> game_ctlr_;
 
     std::string iniPath_;
 
