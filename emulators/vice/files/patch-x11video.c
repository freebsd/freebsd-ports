--- src/arch/unix/x11/xaw/x11video.c.orig	2009-10-21 18:46:45.000000000 +0200
+++ src/arch/unix/x11/xaw/x11video.c	2010-08-03 06:00:50.000000000 +0200
@@ -342,6 +342,9 @@
 int mitshm_failed = 0; /* will be set to true if XShmAttach() failed */
 int shmmajor;          /* major number of MITSHM error codes */
 
+#include <X11/X.h>
+#include <X11/extensions/shmproto.h>
+
 /* Catch XShmAttach()-failure. */
 int shmhandler(Display *display, XErrorEvent *err)
 {
