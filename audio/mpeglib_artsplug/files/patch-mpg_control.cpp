Index: mpeglib/example/yaf/yafmpgplay/mpg_control.cpp
===================================================================
RCS file: /home/kde/kdemultimedia/mpeglib/example/yaf/yafmpgplay/mpg_control.cpp,v
retrieving revision 1.5
diff -u -3 -p -r1.5 mpg_control.cpp
--- mpeglib/example/yaf/yafmpgplay/mpg_control.cpp	2002/11/22 21:52:53	1.5
+++ mpeglib/example/yaf/yafmpgplay/mpg_control.cpp	2002/11/28 08:54:03
@@ -29,14 +29,14 @@ using namespace std;
 #include <stdlib.h>
 #include <math.h>
 
-#if defined(HAVE_GETOPT_H) 
+#if defined(HAVE_GETOPT_H) && !defined(__FreeBSD__)
 #include <getopt.h>
 #endif
 
 // we include our plugin here
 #include "../../../lib/decoder/mpgPlugin.h"
 
-#if defined(HAVE_GETOPT_H) 
+#if defined(HAVE_GETOPT_H) && !defined(__FreeBSD__)
 #include <getopt.h>
 #endif
 
