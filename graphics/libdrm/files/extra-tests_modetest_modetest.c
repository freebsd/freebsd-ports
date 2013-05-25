--- tests/modetest/modetest.c.orig	2013-02-22 00:44:28.203705216 +0100
+++ tests/modetest/modetest.c	2013-02-22 00:44:56.803699770 +0100
@@ -57,6 +57,10 @@
 
 #include "buffers.h"
 
+#ifndef HAVE_STRCHRNUL
+char *strchrnul(const char *, int);
+#endif
+
 drmModeRes *resources;
 int fd, modes;
 
