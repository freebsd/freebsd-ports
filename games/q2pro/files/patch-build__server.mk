--- ./build/server.mk.orig	Mon Dec 25 17:07:02 2006
+++ ./build/server.mk	Mon Dec 25 17:07:02 2006
@@ -22,7 +22,7 @@
 LDFLAGS_WIN32 += -mconsole -lws2_32 -lwinmm -ladvapi32
 
 SRCFILES_LINUX += sys_unix.c
-LDFLAGS_LINUX += -ldl
+LDFLAGS_LINUX += #
 
 include ../../post.mk
 
