--- tools/gpr/gpr.c.orig	Sat Nov 10 21:15:30 2001
+++ tools/gpr/gpr.c	Sat Nov 10 21:15:38 2001
@@ -23,7 +23,6 @@
 #include <queue.h>
 #include <sfstr.h>
 #include <error.h>
-#include "getopt.h"
 
 static const char* usage =
 ": gpr [-o <ofile>] ([-f <prog>] | 'prog') [files]\n\
