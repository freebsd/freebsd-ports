$FreeBSD$

--- ../src/solaris/native/sun/awt/awt_Graphics.c	2010-04-16 21:28:02.000000000 +1100
+++ ../src/solaris/native/sun/awt/awt_Graphics.c	2010-04-16 21:39:52.635333540 +1100
@@ -60,6 +60,10 @@
 #include <sys/ipc.h>
 #include <sys/shm.h>
 #include <X11/extensions/XShm.h>
+#ifndef X_ShmAttach
+#include <X11/Xmd.h>
+#include <X11/extensions/shmproto.h>
+#endif
 
 extern int XShmQueryExtension();
 
