--- target-ethos/utility/utility.cpp.orig	2013-12-21 07:00:03 UTC
+++ target-ethos/utility/utility.cpp
@@ -203,7 +203,7 @@ void Utility::updateShader() {
     video.set(Video::Filter, Video::FilterLinear);
   } else if(config->video.shader == "Display Emulation") {
     if(program->active) {
-      string pathname = program->path("Video Shaders/");
+      string pathname = program->path("shaders/");
       pathname.append("Display Emulation/");
       pathname.append(presentation->systemName, ".shader/");
       if(directory::exists(pathname)) {
