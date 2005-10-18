--- src/sdlmain.cpp.orig	Tue Oct 18 13:24:24 2005
+++ src/sdlmain.cpp	Tue Oct 18 13:25:35 2005
@@ -27,6 +27,7 @@
 #include <time.h>
 #include <stdio.h>
 
+#undef HAVE_GETOPT_LONG
 #ifdef HAVE_GETOPT_LONG
     #include <getopt.h>
 #endif
