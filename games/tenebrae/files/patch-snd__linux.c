--- snd_linux.c.orig	Sun Mar 14 12:25:10 2004
+++ snd_linux.c	Sun Mar 14 12:25:46 2004
@@ -25,7 +25,7 @@
 #include <sys/mman.h>
 #include <sys/shm.h>
 #include <sys/wait.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <stdio.h>
 #include "quakedef.h"
 
