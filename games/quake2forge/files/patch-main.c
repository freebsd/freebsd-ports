--- src/main.c.orig	Fri Feb  7 14:25:46 2003
+++ src/main.c	Fri Feb  7 14:34:14 2003
@@ -49,12 +49,21 @@
 	#include <mntent.h>
 #elif defined(__FreeBSD__) || defined(__bsd__) || defined (__NetBSD__)
 	#include <fstab.h>
+	#include <pthread.h>
 #elif defined(__sun__)
 	#include <sys/file.h>
 #endif
 
 #ifdef HAVE_DLOPEN
 # include <dlfcn.h>
+#endif
+
+/* This should probably go into configure
+ * BSDs and Linux have SIGIO, Solaris needs SIGPOLL
+ * This should probably be changed the other way round
+ * SIGIO as default and SIGPOLL only for Solrais */
+#ifndef SIGPOLL
+#define SIGPOLL SIGIO
 #endif
 
 #include "qcommon.h"
