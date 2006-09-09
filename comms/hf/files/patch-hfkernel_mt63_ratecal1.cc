--- hfkernel/mt63/ratecal1.cc.orig	Sun Jul 30 11:48:34 2006
+++ hfkernel/mt63/ratecal1.cc	Sun Jul 30 11:48:59 2006
@@ -89,6 +89,9 @@
 #ifdef __linux__
 #include <unistd.h> // for usleep()
 #endif
+#ifdef __FreeBSD__ 
+#include <unistd.h>
+#endif
 
 // #ifdef __MSDOS__
 // #include <dos.h> // for delay()
