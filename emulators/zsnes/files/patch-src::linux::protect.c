--- src/linux/protect.c.orig	Tue May  1 21:33:14 2001
+++ src/linux/protect.c	Thu May  3 20:17:23 2001
@@ -16,6 +16,9 @@
 //Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
 #include <stdio.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include <sys/mman.h>
 #include <limits.h>
 #include <unistd.h>
