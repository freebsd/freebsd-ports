--- polyp/polyplib-context.c.orig	Fri Dec 31 14:39:40 2004
+++ polyp/polyplib-context.c	Fri Dec 31 14:40:00 2004
@@ -29,6 +29,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/syslimits.h>
 #include <netdb.h>
 #include <unistd.h>
 #include <sys/stat.h>
