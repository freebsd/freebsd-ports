--- test/render.c.orig	Wed Dec 15 12:04:53 2004
+++ test/render.c	Wed Dec 15 12:42:01 2004
@@ -12,6 +12,7 @@
 #include <swfdec_render.h>
 #include <swfdec_sprite.h>
 #include <swfdec_buffer.h>
+#include <sys/signal.h>
 #include <ucontext.h>
 #include <sys/mman.h>
 
