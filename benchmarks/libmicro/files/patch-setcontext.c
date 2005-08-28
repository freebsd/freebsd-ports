--- setcontext.c.orig	Sat Aug  6 16:15:12 2005
+++ setcontext.c	Sat Aug  6 16:15:31 2005
@@ -36,6 +36,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
+#include <signal.h>
 #include <ucontext.h>
 
 #include "libmicro.h"
