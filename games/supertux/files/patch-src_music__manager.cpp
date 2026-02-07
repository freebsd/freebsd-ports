Fix build with Clang6.

file is a const std::string&, which needs to be (explicitly) copied
into the pair when the pair's first member is std::string (non-const).

--- src/music_manager.cpp.orig	2018-07-05 12:45:32 UTC
+++ src/music_manager.cpp
@@ -66,7 +66,7 @@ MusicManager::exists_music(const std::string& file)
   // insert into music list
   std::pair<std::map<std::string, MusicResource>::iterator, bool> result = 
     musics.insert(
-        std::make_pair<std::string, MusicResource> (file, MusicResource()));
+        std::make_pair<std::string, MusicResource> (std::string(file), MusicResource()));
   MusicResource& resource = result.first->second;
   resource.manager = this;
   resource.music = song;
