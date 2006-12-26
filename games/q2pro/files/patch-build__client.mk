--- ./build/client.mk.orig	Mon Dec 25 17:07:02 2006
+++ ./build/client.mk	Mon Dec 25 17:07:02 2006
@@ -42,7 +42,7 @@
 #
 SRCFILES_LINUX = sys_unix.c snd_linux.c cd_linux.c vid_sdl.c in_linux.c
 ASMFILES_LINUX = snd_mixa.s
-LDFLAGS_LINUX += -lz -ldl -lSDL
+LDFLAGS_LINUX += -lz `sdl-config --libs`
 
 include ../../post.mk
 
