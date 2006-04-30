--- libgnomevfs/gnome-vfs-address.c.orig	Wed Apr 12 10:16:28 2006
+++ libgnomevfs/gnome-vfs-address.c	Thu Apr 20 09:52:12 2006
@@ -32,6 +32,7 @@
 #include <sys/types.h>
 
 #ifndef G_OS_WIN32
+#include <sys/socket.h>
 #include <sys/select.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
