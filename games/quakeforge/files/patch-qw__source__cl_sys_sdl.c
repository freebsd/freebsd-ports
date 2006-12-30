--- qw/source/cl_sys_sdl.c.orig	Tue Jan 20 00:47:27 2004
+++ qw/source/cl_sys_sdl.c	Sat Dec 30 16:44:37 2006
@@ -63,6 +63,7 @@
 #include "QF/console.h"
 #include "QF/qargs.h"
 #include "QF/sys.h"
+#include "QF/progs.h"
 
 #include "client.h"
 #include "compat.h"
@@ -107,6 +108,9 @@
 	fcntl (0, F_SETFL, fcntl (0, F_GETFL, 0) & ~O_NONBLOCK);
 #endif
 }
+
+extern void Key_Progs_Init (progs_t *pr);
+void (*x)() = Key_Progs_Init;
 
 #ifndef SDL_main
 # define SDL_main main
