--- polyp/polyplib-context.c.orig	Fri Oct 29 17:05:24 2004
+++ polyp/polyplib-context.c	Fri Oct 29 17:05:39 2004
@@ -34,6 +34,7 @@
 #include <sys/stat.h>
 #include <errno.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 #include "polyplib-internal.h"
 #include "polyplib-context.h"
