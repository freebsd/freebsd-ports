Remove esound dependency.  In recent versions of libgnome,
gnome_sound_connection_get() always returns -1, so esd_sample_play()
can never work.

--- src/sound.cpp.orig	2018-08-17 12:52:26 UTC
+++ src/sound.cpp
@@ -18,9 +18,6 @@
  * USA.
  */
 
-#include <libgnome/gnome-sound.h>
-#include <esd.h>
-
 #include "sound.hpp"
 
 
@@ -40,16 +37,4 @@ Sound::~Sound()
 
 void Sound::play(const std::string &name)
 {
-  int id;
-  
-  cache_map::iterator i = cache.find(name);
-  if (i != cache.end())
-    id = i->second;
-  else {
-    id = gnome_sound_sample_load(name.c_str(),
-			    (MONSTER_MASHER_SOUND_DIR + name).c_str());
-    cache.insert(make_pair(name, id));
-  }
-
-  esd_sample_play(gnome_sound_connection_get(), id);
 }
