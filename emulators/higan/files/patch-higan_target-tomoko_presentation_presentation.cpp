--- higan/target-tomoko/presentation/presentation.cpp.orig	2017-01-13 17:52:31 UTC
+++ higan/target-tomoko/presentation/presentation.cpp
@@ -278,7 +278,7 @@ auto Presentation::toggleFullScreen() ->
 }
 
 auto Presentation::loadShaders() -> void {
-  auto pathname = locate("Video Shaders/");
+  auto pathname = locateShared("Video Shaders/");
 
   if(settings["Video/Driver"].text() == "OpenGL") {
     for(auto shader : directory::folders(pathname, "*.shader")) {
