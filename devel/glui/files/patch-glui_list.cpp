--- glui_list.cpp.orig	2007-11-04 08:19:40.000000000 +0300
+++ glui_list.cpp	2010-02-08 19:59:12.000000000 +0300
@@ -30,7 +30,7 @@
 
 #include "glui_internal_control.h"
 #include <cmath>
-#include <sys/timeb.h>
+#include <sys/time.h>
 
 /****************************** GLUI_List::GLUI_List() **********/
 
@@ -100,9 +100,9 @@
 {
   int tmp_line;
   unsigned long int ms;
-  timeb time;
-  ftime(&time);
-  ms = time.millitm + (time.time)*1000;
+  struct timeval tv;
+  gettimeofday(&tv, NULL);
+  ms = tv.tv_usec/100 + (tv.tv_sec)*1000;
 
   tmp_line = find_line( local_x-x_abs, local_y-y_abs-5 );  
   if ( tmp_line == -1 ) {
