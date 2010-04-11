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
