--- ./build/client.mk.orig	Sun Feb  4 15:31:20 2007
+++ ./build/client.mk	Sun Feb  4 16:13:09 2007
@@ -27,9 +27,14 @@
 RESFILES_WIN32 += q2.rc
 
 SRCFILES_LINUX = sys_unix.c snd_linux.c cd_linux.c vid_sdl.c in_linux.c
+ifdef USE_X86_ASM
 ASMFILES_LINUX = snd_mixa.s
+else
+SRCFILES_LINUX += snd_mix.c
+CFLAGS_LINUX += -DC_ONLY
+endif
 CFLAGS_LINUX += $(CFLAGS_SDL)
-LDFLAGS_LINUX += -ldl -lX11 $(LDFLAGS_SDL)
+LDFLAGS_LINUX += -lX11 $(LDFLAGS_SDL)
 
 include ../../post.mk
 
