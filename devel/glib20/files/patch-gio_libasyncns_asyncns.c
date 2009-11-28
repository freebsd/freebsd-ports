--- gio/libasyncns/asyncns.c.orig	2009-05-05 15:25:10.000000000 -0400
+++ gio/libasyncns/asyncns.c	2009-05-05 15:25:51.000000000 -0400
@@ -35,6 +35,8 @@
 #include <errno.h>
 #include <sys/wait.h>
 #include <sys/types.h>
+#include <sys/time.h>
+#include <sys/resource.h>
 #include <pwd.h>
 #include <netinet/in.h>
 #include <arpa/nameser.h>
