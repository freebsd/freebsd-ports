- https://gitlab.com/OpenMusicKontrollers/moony.lv2/-/issues/2

--- subprojects/d2tk/src/util_spawn.c.orig	2021-03-06 18:21:48 UTC
+++ subprojects/d2tk/src/util_spawn.c
@@ -23,6 +23,7 @@
 #include <sched.h>
 #include <sys/wait.h>
 #include <sys/mman.h>
+#include <sys/signal.h>
 
 #include <d2tk/util.h>
 
