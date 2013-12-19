--- tests/modetest/modetest.c.orig	2013-09-16 22:56:20.000000000 +0200
+++ tests/modetest/modetest.c	2013-11-07 11:32:10.534114644 +0100
@@ -59,6 +59,10 @@
 
 #include "buffers.h"
 
+#ifndef HAVE_STRCHRNUL
+char *strchrnul(const char *, int);
+#endif
+
 struct crtc {
 	drmModeCrtc *crtc;
 	drmModeObjectProperties *props;
