Index: mpeglib/example/yaf/yaftplay/tplay_control.cpp
===================================================================
RCS file: /home/kde/kdemultimedia/mpeglib/example/yaf/yaftplay/tplay_control.cpp,v
retrieving revision 1.3
diff -u -3 -p -r1.3 tplay_control.cpp
--- mpeglib/example/yaf/yaftplay/tplay_control.cpp	2002/11/22 21:52:54	1.3
+++ mpeglib/example/yaf/yaftplay/tplay_control.cpp	2002/11/28 08:55:41
@@ -29,7 +29,7 @@ using namespace std;
 #include "../../../lib/decoder/tplayPlugin.h"
 
 
-#if defined(HAVE_GETOPT_H) 
+#if defined(HAVE_GETOPT_H) && !defined(__FreeBSD__)
 #include <getopt.h>
 #endif
 
