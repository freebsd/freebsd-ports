--- src/jmixer.cpp.orig	Sat Apr 10 02:50:43 2004
+++ src/jmixer.cpp	Mon Apr 19 22:49:59 2004
@@ -20,18 +20,18 @@
  */
 
 #include <iostream>
-#include <math.h>
-#include <stdio.h>
-#include <stdlib.h>
+#include <cmath>
+#include <cstdio>
+#include <cstdlib>
 #include <unistd.h>
 #include <dirent.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
-#include <errno.h>
+#include <cerrno>
 #include <fcntl.h>
 #include <sys/soundcard.h>
-#include <string.h>
-#include <signal.h>
+#include <cstring>
+#include <csignal>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <termios.h>
@@ -624,10 +624,11 @@
   return true;
 }
 
-/* this is the function selecting files for the scandir
-   on freebsd systems you should change the following line to:
-   int selector(struct dirent *dir) {    */
+#if defined(__FreeBSD__)
+int selector(struct dirent *dir) {
+#else
 int selector(const struct dirent *dir) {
+#endif
   if( strncasecmp(dir->d_name+strlen(dir->d_name)-4,".mp3",4)==0
 #ifdef HAVE_VORBIS
       || strncasecmp(dir->d_name+strlen(dir->d_name)-4,".ogg",4)==0
