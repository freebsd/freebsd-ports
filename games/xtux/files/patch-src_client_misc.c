--- src/client/misc.c.orig	Tue Nov 14 07:18:38 2000
+++ src/client/misc.c	Sat Dec 23 06:47:57 2000
@@ -4,6 +4,7 @@
 #include <string.h>
 #include <pwd.h>
 #include <unistd.h>
+#include <sys/syslimits.h>
 
 #include "xtux.h"
 #include "client.h"
