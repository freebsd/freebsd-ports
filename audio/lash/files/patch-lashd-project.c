--- lashd/project.c.orig	Sat Jan 13 15:21:41 2007
+++ lashd/project.c	Sat Jan 13 15:23:06 2007
@@ -33,6 +33,7 @@
 #include <signal.h>
 #include <errno.h>
 #include <stdio.h>
+#include <unistd.h>
 
 #include <jack/jack.h>
 #include <libxml/tree.h>
