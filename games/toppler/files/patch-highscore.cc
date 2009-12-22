--- highscore.cc.orig	2009-10-11 08:46:06.000000000 +0900
+++ highscore.cc	2009-11-16 01:09:40.000000000 +0900
@@ -24,6 +24,7 @@
 #include <string.h>
 #include <stdio.h>
 #include <fcntl.h>
+#include <sys/stat.h>
 #include <unistd.h>
 
 #ifdef __QNXNTO__
