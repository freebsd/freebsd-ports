--- magick/xwindow.c.old	Sun Nov 24 15:07:53 2002
+++ magick/xwindow.c	Sun Nov 24 15:08:16 2002
@@ -57,6 +57,16 @@
 #include "log.h"
 #include "utility.h"
 #include "version.h"
+#if defined(HasSharedMemory)
+#include <machine/param.h>
+
+#if __FreeBSD__ >= 5
+typedef unsigned short ushort;	/* needed for sys/ipc.h at the moment */
+#endif
+#include <sys/types.h>
+#include <sys/ipc.h>
+#include <sys/shm.h>
+#endif
 #include "xwindow.h"
 #if defined(HasX11)
 
