--- src/dump.cpp.orig	2016-05-01 20:07:33 UTC
+++ src/dump.cpp
@@ -584,7 +584,7 @@ int main(int argc, char *argv[]) {
     }
 
     LOG(Log::k_FLG_INFO, "Main", "main", ("----- Initializing application..."))
-    std::auto_ptr<EditorApp> app(new EditorApp(disable_sound));
+    std::unique_ptr<EditorApp> app(new EditorApp(disable_sound));
 
     if (app->initialize(iniPath)) {
         LOG(Log::k_FLG_INFO, "Main", "main", ("----- Initializing application completed"))
