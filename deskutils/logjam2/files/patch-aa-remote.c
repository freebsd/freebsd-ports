--- src/remote.orig	Sat Jun  7 17:39:10 2003
+++ src/remote.c	Sat Jun  7 17:39:20 2003
@@ -14,8 +14,8 @@
 
 #include <gtk/gtk.h>
 #ifndef G_OS_WIN32
-#include <sys/select.h>
 #include <sys/types.h>
+#include <sys/select.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <unistd.h>
