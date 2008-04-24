--- ./source/sys_bsd.cpp.orig	2006-09-26 20:32:53.000000000 -0300
+++ ./source/sys_bsd.cpp	2008-04-21 14:45:17.000000000 -0300
@@ -29,13 +29,13 @@
 
 // HEADER FILES ------------------------------------------------------------
 
-#include "gamedefs.h"
 #include <signal.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <dirent.h>
 #include <sys/stat.h>
 #include <sys/time.h>
+#include "gamedefs.h"
 
 #ifdef DJGPP
 #include <dpmi.h>
