--- src/linux/rw_aa.c.orig	Thu Jun 12 18:26:51 2003
+++ src/linux/rw_aa.c	Thu Jun 12 18:30:59 2003
@@ -53,15 +53,18 @@
 */
 
 #include <termios.h>
+#include <unistd.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
-#include <sys/vt.h>
 #include <stdarg.h>
 #include <stdio.h>
 #include <signal.h>
 #include <sys/mman.h>
 #include <dlfcn.h>
+#ifdef __linux__
+#include <sys/vt.h>
 #include <asm/io.h>
+#endif
 
 #include <aalib.h>
 
@@ -240,7 +243,6 @@
 */
 void SWimp_SetPalette( const unsigned char *palette )
 {
-	static int tmppal[256*3];
 	const unsigned char *pal;
 	int i;
 
