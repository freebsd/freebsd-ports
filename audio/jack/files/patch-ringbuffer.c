--- libjack/ringbuffer.c.orig	Tue Mar  9 18:57:50 2004
+++ libjack/ringbuffer.c	Tue Mar  9 18:58:07 2004
@@ -22,6 +22,7 @@
 
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 #include <jack/ringbuffer.h>
 
