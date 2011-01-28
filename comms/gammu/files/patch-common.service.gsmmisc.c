--- libgammu/service/gsmmisc.c.orig	2010-07-12 15:51:05.000000000 +0400
+++ libgammu/service/gsmmisc.c	2011-01-28 13:21:17.940543932 +0300
@@ -5,6 +5,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/stat.h>
+#include <sys/socket.h>
 
 #include <gammu-keys.h>
 #include <gammu-debug.h>
