--- src/platform/sdl2/build.sh.orig	2026-08-18 20:24:48 UTC
+++ src/platform/sdl2/build.sh
@@ -1,7 +1,7 @@ set -e
 set -e
 
 # Use this compilation line to build SDL2/GLES version, GLES2 version.
-clang++ -DSDL2_GLES -D_GAPI_GLES2 -std=c++11 `sdl2-config --cflags` -O3 -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections -Wl,--gc-sections -Wno-invalid-source-encoding -DNDEBUG -D__SDL2__ main.cpp ../../libs/stb_vorbis/stb_vorbis.c ../../libs/minimp3/minimp3.cpp ../../libs/tinf/tinflate.c -I../../ -o OpenLara `sdl2-config --libs` -lGLESv2 -lEGL -lm -lrt -lpthread -lasound -ludev
+#clang++ -DSDL2_GLES -D_GAPI_GLES2 -std=c++11 `sdl2-config --cflags` -O3 -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections -Wl,--gc-sections -Wno-invalid-source-encoding -DNDEBUG -D__SDL2__ main.cpp ../../libs/stb_vorbis/stb_vorbis.c ../../libs/minimp3/minimp3.cpp ../../libs/tinf/tinflate.c -I../../ -o OpenLara `sdl2-config --libs` -lGLESv2 -lEGL -lm -lrt -lpthread -lasound -ludev
 strip ../../../bin/OpenLara --strip-all --remove-section=.comment --remove-section=.note
 
 #g++ -DSDL2_GLES -D_GAPI_GLES2 -std=c++11 `sdl2-config --cflags` -O3 -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections -Wl,--gc-sections -DNDEBUG -D__SDL2__ main.cpp ../../libs/stb_vorbis/stb_vorbis.c ../../libs/minimp3/minimp3.cpp ../../libs/tinf/tinflate.c -I../../ -o OpenLara `sdl2-config --libs` -lGLESv2 -lEGL -lm -lrt -lpthread -lasound -ludev
@@ -10,4 +10,4 @@ strip ../../../bin/OpenLara --strip-all --remove-secti
 #g++ -DSDL2_GLES -std=c++11 `sdl2-config --cflags` -O3 -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections -Wl,--gc-sections -DNDEBUG -D__SDL2__ main.cpp ../../libs/stb_vorbis/stb_vorbis.c ../../libs/minimp3/minimp3.cpp ../../libs/tinf/tinflate.c -I../../ -o OpenLara `sdl2-config --libs` -lGLESv2 -lEGL -lm -lrt -lpthread -lasound -ludev
 
 # Use this compilation line to build SDL2/OpenGL version.
-#g++ -std=c++11 `sdl2-config --cflags` -O3 -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections -Wl,--gc-sections -DNDEBUG -D__SDL2__ -D_SDL2_OPENGL main.cpp ../../libs/stb_vorbis/stb_vorbis.c ../../libs/minimp3/minimp3.cpp ../../libs/tinf/tinflate.c -I../../ -o OpenLara `sdl2-config --libs` -lGL -lm -lrt -lpthread -lasound -ludev
+g++ -std=c++11 `sdl2-config --cflags` -O3 -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections -Wl,--gc-sections -Wno-invalid-source-encoding -DNDEBUG -D__SDL2__ -D_SDL2_OPENGL main.cpp ../../libs/stb_vorbis/stb_vorbis.c ../../libs/minimp3/minimp3.cpp ../../libs/tinf/tinflate.c -I../../ -o OpenLara `sdl2-config --libs` -lGL -lm -lrt -lpthread
