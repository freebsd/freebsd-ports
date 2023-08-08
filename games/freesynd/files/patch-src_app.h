--- src/app.h.orig	2016-05-01 20:07:33 UTC
+++ src/app.h
@@ -153,13 +153,13 @@ class App : public Singleton < App > { (private)
 private:
     bool running_;
     /*! A structure to hold general application informations.*/
-    std::auto_ptr<AppContext> context_;
+    std::unique_ptr<AppContext> context_;
     /*! A structure to hold player informations.*/
-    std::auto_ptr<GameSession> session_;
+    std::unique_ptr<GameSession> session_;
     /*! Controls the game logic. */
-    std::auto_ptr<GameController> game_ctlr_;
-    std::auto_ptr<Screen> screen_;
-    std::auto_ptr<System> system_;
+    std::unique_ptr<GameController> game_ctlr_;
+    std::unique_ptr<Screen> screen_;
+    std::unique_ptr<System> system_;
 
     std::string iniPath_;
 
