--- src/freesynd.cpp.orig	2016-05-01 20:07:33 UTC
+++ src/freesynd.cpp
@@ -229,7 +229,7 @@ int main(int argc, char *argv[]) {
     }
 
     LOG(Log::k_FLG_INFO, "Main", "main", ("----- Initializing application..."))
-    std::auto_ptr<App> app(new App(disable_sound));
+    std::unique_ptr<App> app(new App(disable_sound));
 
     if (app->initialize(iniPath)) {
         // setting the cheat codes
