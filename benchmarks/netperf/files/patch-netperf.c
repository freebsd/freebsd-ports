--- netperf.c~	Fri Jun 21 22:42:53 2002
+++ netperf.c	Tue Jan 21 00:55:34 2003
@@ -47,6 +47,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/types.h>
 
 #ifdef WIN32
 #include <windows.h>
