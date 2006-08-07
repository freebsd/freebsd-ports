--- src/jmixer.cpp.orig	Fri Aug  4 11:44:33 2006
+++ src/jmixer.cpp	Fri Aug  4 11:46:02 2006
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
 
-#include <string.h>
-#include <signal.h>
+#include <cstring>
+#include <csignal>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <termios.h>
@@ -640,7 +640,7 @@
 /* this is the function selecting files for the scandir
    on freebsd systems you should change the following line to:
    int selector(struct dirent *dir) {    */
-int selector(const struct dirent *dir) {
+int selector(struct dirent *dir) {
   if( strncasecmp(dir->d_name+strlen(dir->d_name)-4,".mp3",4)==0
 #ifdef HAVE_VORBIS
       || strncasecmp(dir->d_name+strlen(dir->d_name)-4,".ogg",4)==0
