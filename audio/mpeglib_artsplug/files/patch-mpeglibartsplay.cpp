Index: mpeglib_artsplug/mpeglibartsplay.cpp
===================================================================
RCS file: /home/kde/kdemultimedia/mpeglib_artsplug/mpeglibartsplay.cpp,v
retrieving revision 1.13
diff -u -3 -p -r1.13 mpeglibartsplay.cpp
--- mpeglib_artsplug/mpeglibartsplay.cpp	2002/06/15 00:17:11	1.13
+++ mpeglib_artsplug/mpeglibartsplay.cpp	2002/11/28 10:09:03
@@ -26,7 +26,7 @@
 
 using namespace std;
 
-#if defined(HAVE_GETOPT_H) 
+#if defined(HAVE_GETOPT_H) && !defined(__FreeBSD__)
 #include <getopt.h>
 #endif
 
