--- build/server.mk.orig	Sun Feb  4 16:29:23 2007
+++ build/server.mk	Sun Feb  4 16:30:00 2007
@@ -22,7 +22,6 @@
 RESFLAGS_WIN32+=-DDEDICATED_ONLY
 
 SRCFILES_LINUX+=sys_unix.c
-LDFLAGS_LINUX+=-ldl
 
 include ../../post.mk
 
