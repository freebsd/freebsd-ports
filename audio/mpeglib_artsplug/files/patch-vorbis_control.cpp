Index: mpeglib/example/yaf/yafvorbis/vorbis_control.cpp
===================================================================
RCS file: /home/kde/kdemultimedia/mpeglib/example/yaf/yafvorbis/vorbis_control.cpp,v
retrieving revision 1.3
diff -u -3 -p -r1.3 vorbis_control.cpp
--- mpeglib/example/yaf/yafvorbis/vorbis_control.cpp	2000/12/03 22:05:05	1.3
+++ mpeglib/example/yaf/yafvorbis/vorbis_control.cpp	2002/11/28 08:56:38
@@ -29,7 +29,7 @@
 
 #include "../../../lib/decoder/vorbisPlugin.h"
 
-#if defined(HAVE_GETOPT_H) 
+#if defined(HAVE_GETOPT_H) && !defined(__FreeBSD__)
 #include <getopt.h>
 #endif
 
