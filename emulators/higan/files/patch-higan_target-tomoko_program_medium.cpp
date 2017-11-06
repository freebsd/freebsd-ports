--- higan/target-tomoko/program/medium.cpp.orig	2017-01-13 10:43:46 UTC
+++ higan/target-tomoko/program/medium.cpp
@@ -17,7 +17,7 @@ auto Program::loadMedium() -> void {
 auto Program::loadMedium(Emulator::Interface& interface, const Emulator::Interface::Medium& medium) -> void {
   unloadMedium();
 
-  mediumPaths.append(locate({medium.name, ".sys/"}));
+  mediumPaths.append(locateShared({medium.name, ".sys/"}));
 
   Emulator::audio.reset(2, audio->get(Audio::Frequency).get<uint>(44100));
   inputManager->bind(emulator = &interface);
