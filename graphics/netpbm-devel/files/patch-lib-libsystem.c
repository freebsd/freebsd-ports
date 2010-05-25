--- lib/libsystem.c.orig	2010-03-24 03:06:41.000000000 +0100
+++ lib/libsystem.c	2010-05-25 07:31:25.000000000 +0200
@@ -154,6 +154,13 @@
 }
 
 
+#ifndef SIGRTMIN
+#define SIGRTMIN 65
+#endif
+#ifndef SIGRTMAX
+#define SIGRTMAX 126
+#endif
+
 
 static const char *
 signalName(unsigned int const signalClass) {
