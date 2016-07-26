--- src/jmixer.cpp.orig	2004-12-16 11:04:31 UTC
+++ src/jmixer.cpp
@@ -20,18 +20,19 @@
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
+#include <sys/param.h>
+#include <cerrno>
 #include <fcntl.h>
 
-#include <string.h>
-#include <signal.h>
+#include <cstring>
+#include <csignal>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <termios.h>
@@ -640,7 +641,11 @@ bool Stream_mixer::set_playmode(int ch, 
 /* this is the function selecting files for the scandir
    on freebsd systems you should change the following line to:
    int selector(struct dirent *dir) {    */
+#if defined(__FreeBSD__) && __FreeBSD_version < 800501
+int selector(struct dirent *dir) {
+#else
 int selector(const struct dirent *dir) {
+#endif
   if( strncasecmp(dir->d_name+strlen(dir->d_name)-4,".mp3",4)==0
 #ifdef HAVE_VORBIS
       || strncasecmp(dir->d_name+strlen(dir->d_name)-4,".ogg",4)==0
