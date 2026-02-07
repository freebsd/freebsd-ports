--- libgammu/service/gsmmisc.c.orig	2015-12-08 10:38:12 UTC
+++ libgammu/service/gsmmisc.c
@@ -5,6 +5,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/stat.h>
+#include <sys/socket.h>
 
 #include <gammu-keys.h>
 #include <gammu-debug.h>
