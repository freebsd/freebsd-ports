--- ./glib/deprecated/gthread.h.orig	2012-05-27 17:07:04.000000000 +0200
+++ ./glib/deprecated/gthread.h	2012-05-27 17:07:19.000000000 +0200
@@ -120,6 +120,7 @@
                                 gpointer          user_data);
 
 #ifndef G_OS_WIN32
+#include <sys/types.h>
 #include <pthread.h>
 #endif
 
