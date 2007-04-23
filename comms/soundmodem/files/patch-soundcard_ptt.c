--- soundcard/ptt.c.orig	Sat Nov  9 10:31:53 2002
+++ soundcard/ptt.c	Mon Apr 23 10:24:36 2007
@@ -48,6 +48,9 @@
 
 #ifdef HAVE_LINUX_PPDEV_H
 #include <linux/ppdev.h>
+#elif defined(__FreeBSD__)
+#include <dev/ppbus/ppi.h>
+#include <dev/ppbus/ppbconf.h>
 #else
 #include "ppdev.h"
 #endif
@@ -62,7 +65,11 @@
 
 struct modemparams pttparams[] = {
 	{ "file", "PTT Driver", "Path name of the serial or parallel port driver for outputting PTT", "none", MODEMPAR_COMBO, 
+#ifdef __FreeBSD__
+	  { c: { { "none", "/dev/ttyd0", "/dev/ttyd1", "/dev/ppi0", "/dev/ppi1" } } } },
+#else
 	  { c: { { "none", "/dev/ttyS0", "/dev/ttyS1", "/dev/parport0", "/dev/parport1" } } } },
+#endif
 	{ NULL }
 };
 
@@ -87,7 +94,11 @@
 	if (!ioctl(fd, TIOCMBIC, &y)) {
 		state->fd = fd;
 		state->mode = serport;
+#ifdef __FreeBSD__
+	} else if (!ioctl(fd, PPISDATA, &x)) {
+#else
 	} else if (!ioctl(fd, PPCLAIM, 0) && !ioctl(fd, PPRDATA, &x)) {
+#endif
 		state->fd = fd;
 		state->mode = parport;
 	} else {
@@ -122,7 +133,11 @@
 #endif
 	} else if (state->mode == parport) {
 		reg = state->ptt | (state->dcd << 1);
+#ifdef __FreeBSD__
+		ioctl(state->fd, PPISDATA, &reg);
+#else
 		ioctl(state->fd, PPWDATA, &reg);
+#endif
 	}
 }
 
@@ -148,7 +163,11 @@
 #endif
 	} else if (state->mode == parport) {
 		reg = state->ptt | (state->dcd << 1);
+#ifdef __FreeBSD__
+		ioctl(state->fd, PPISDATA, &reg);
+#else
 		ioctl(state->fd, PPWDATA, &reg);
+#endif
 	}
 }
 
