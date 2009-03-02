--- libgammu/service/gsmmisc.c.orig	Fri Dec 30 18:18:47 2005
+++ libgammu/service/gsmmisc.c	Fri Dec 30 18:19:07 2005
@@ -3,6 +3,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/stat.h>
+#include <sys/socket.h>
 
 #include <gammu-keys.h>
 #include <gammu-debug.h>
