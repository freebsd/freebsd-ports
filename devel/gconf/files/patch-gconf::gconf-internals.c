--- gconf/gconf-internals.c.orig	Thu Mar 14 22:39:51 2002
+++ gconf/gconf-internals.c	Fri Sep 27 00:37:23 2002
@@ -28,6 +28,9 @@
 #include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
@@ -3040,6 +3043,8 @@
 
       if (gconf_file_exists (GCONF_BINDIR"/gconfd-2"))
         argv[0] = g_strconcat (GCONF_BINDIR, "/gconfd-2", NULL);
+      else if (gconf_file_exists (GCONF_PREFIX"/libexec/gconfd-2"))
+	argv[0] = g_strconcat (GCONF_PREFIX, "/libexec/gconfd-2", NULL);
       else
         argv[0] = g_strconcat (GCONF_BINDIR, "/" GCONFD, NULL);
 
