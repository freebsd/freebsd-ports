Index: mpeglib/example/yaf/yafsplay/splay_control.cpp
===================================================================
RCS file: /home/kde/kdemultimedia/mpeglib/example/yaf/yafsplay/splay_control.cpp,v
retrieving revision 1.6
diff -u -3 -p -r1.6 splay_control.cpp
--- mpeglib/example/yaf/yafsplay/splay_control.cpp	2002/11/22 21:52:54	1.6
+++ mpeglib/example/yaf/yafsplay/splay_control.cpp	2002/11/28 08:51:50
@@ -28,7 +28,7 @@ using namespace std;
 // we include our plugin here
 #include "../../../lib/decoder/splayPlugin.h"
 
-#if defined(HAVE_GETOPT_H) 
+#if defined(HAVE_GETOPT_H) && !defined(__FreeBSD__)
 #include <getopt.h>
 #endif
 
