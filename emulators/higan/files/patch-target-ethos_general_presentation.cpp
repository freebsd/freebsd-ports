--- target-ethos/general/presentation.cpp.orig	2013-12-06 20:19:40 UTC
+++ target-ethos/general/presentation.cpp
@@ -235,7 +235,7 @@ void Presentation::bootstrap() {
 void Presentation::loadShaders() {
   //only the OpenGL driver has video shader support
   if(config->video.driver == "OpenGL") {
-    string pathname = program->path("Video Shaders/");
+    string pathname = program->path("shaders/");
     lstring shaders = directory::folders(pathname, "*.shader");
     for(auto& name : shaders) {
       auto shader = new RadioItem;
