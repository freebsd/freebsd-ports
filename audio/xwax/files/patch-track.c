--- track.c.orig	2024-06-25 02:02:16 UTC
+++ track.c
@@ -22,6 +22,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
+#include <sys/signal.h>
 #include <sys/wait.h>
 #include <sys/mman.h> /* mlock() */
 
