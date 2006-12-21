--- ./cl_tcl.c.orig	Tue Apr 18 17:59:55 2006
+++ ./cl_tcl.c	Tue Aug 29 20:59:12 2006
@@ -24,6 +24,7 @@
 #define STATIC_BUILD
 #include <tcl.h>
 #include <time.h>
+#include <dlfcn.h>
 #include "quakedef.h"
 
 extern cmd_function_t *impulse_cmd;
