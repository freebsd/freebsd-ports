--- setcontext.c.orig	2011-05-11 00:58:23 UTC
+++ setcontext.c
@@ -31,6 +31,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
+#include <signal.h>
 #include <ucontext.h>
 
 #include "libmicro.h"
