--- ./src/faulthandler.h.orig	2007-06-11 14:29:30.000000000 -0400
+++ ./src/faulthandler.h	2014-08-11 10:17:47.000000000 -0400
@@ -46,6 +46,7 @@
 #include <execinfo.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <cxxabi.h>      // Needed for __cxa_demangle
 #include <signal.h>
 #include <string>
