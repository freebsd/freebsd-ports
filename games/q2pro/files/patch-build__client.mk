--- build/client.mk.orig	Sat Jan 20 12:40:15 2007
+++ build/client.mk	Sat Jan 20 12:40:20 2007
@@ -41,8 +41,13 @@
 # linux
 #
 SRCFILES_LINUX = sys_unix.c snd_linux.c cd_linux.c vid_sdl.c in_linux.c
+ifdef USE_X86_ASM
 ASMFILES_LINUX = snd_mixa.s
-LDFLAGS_LINUX += -lz -ldl -lSDL
+else
+SRCFILES_LINUX += snd_mix.c
+CFLAGS_LINUX += -DC_ONLY
+endif
+LDFLAGS_LINUX += -lz `sdl-config --libs`
 
 include ../../post.mk
 
