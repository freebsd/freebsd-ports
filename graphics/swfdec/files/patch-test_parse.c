--- test/parse.c.orig	Sat Apr 15 04:33:30 2006
+++ test/parse.c	Sat Apr 15 04:33:48 2006
@@ -11,6 +11,7 @@
 #include <swfdec_render.h>
 #include <swfdec_sprite.h>
 #include <swfdec_buffer.h>
+#include <sys/signal.h>
 #include <ucontext.h>
 #include <sys/mman.h>
 
