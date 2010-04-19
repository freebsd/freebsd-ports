$FreeBSD: /tmp/pcvs/ports/java/jdk16/files/patch-j2se-awt-awt_GraphicsEnv.h,v 1.1 2010-04-19 06:18:54 glewis Exp $

--- ../../j2se/src/solaris/native/sun/awt/awt_GraphicsEnv.h.orig	2010-04-16 21:28:02.000000000 +1100
+++ ../../j2se/src/solaris/native/sun/awt/awt_GraphicsEnv.h	2010-04-16 21:39:52.635333540 +1100
@@ -24,6 +24,10 @@
 #include <sys/ipc.h>
 #include <sys/shm.h>
 #include <X11/extensions/XShm.h>
+#ifndef X_ShmAttach
+#include <X11/Xmd.h>
+#include <X11/extensions/shmproto.h>
+#endif
 
 extern int XShmQueryExtension();
 
