--- src/main.cpp.orig	Sat Apr 13 14:35:57 2002
+++ src/main.cpp	Sat Apr 13 14:37:01 2002
@@ -30,8 +30,10 @@
 #include <qtextcodec.h>
 
 #ifdef _WS_X11_
+#ifndef __FreeBSD__
 #include <getopt.h>
 #endif
+#endif
 
 #ifdef _WS_WIN_
 #include <windows.h>
@@ -46,6 +48,7 @@
 #endif
 
 #ifdef _WS_X11_
+#ifndef __FreeBSD__
 static struct option const long_options[] =
 {
     {"help", no_argument, 0, 'h'},
@@ -91,6 +94,7 @@
     return optind;
 }
 #endif
+#endif
 
 #ifdef _WS_WIN_
 /*
@@ -134,7 +138,11 @@
 int main( int argc, char **argv )
 {
 #ifdef _WS_X11_
+#ifndef __FreeBSD__
     int i = decode_switches (argc, argv);
+#else
+    int i=1;
+#endif
 #else
     int i=1;
 #endif
