--- getcontext.c.orig	Sat Aug  6 16:11:21 2005
+++ getcontext.c	Sat Aug  6 16:11:45 2005
@@ -39,6 +39,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
+#include <signal.h>
 #include <ucontext.h>
 
 #include "libmicro.h"
