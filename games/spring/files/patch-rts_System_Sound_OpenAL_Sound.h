In file included from rts/System/Sound/OpenAL/Sound.cpp:7:
/usr/local/include/AL/alc.h:34:16: error: typedef 'ALCdevice' cannot be referenced with a struct specifier
typedef struct ALCdevice ALCdevice;
               ^
rts/System/Sound/OpenAL/Sound.h:23:33: note: declared here
typedef struct ALCdevice_struct ALCdevice;
                                ^
1 error generated.

--- rts/System/Sound/OpenAL/Sound.h.orig	2019-11-30 22:16:43 UTC
+++ rts/System/Sound/OpenAL/Sound.h
@@ -11,6 +11,7 @@
 #include <vector>
 #include <boost/ptr_container/ptr_vector.hpp>
 #include <boost/thread/recursive_mutex.hpp>
+#include <AL/alc.h>
 
 #include "System/float3.h"
 
@@ -19,8 +20,6 @@
 class CSoundSource;
 class SoundBuffer;
 class SoundItem;
-struct ALCdevice_struct;
-typedef struct ALCdevice_struct ALCdevice;
 
 namespace boost {
 	class thread;
