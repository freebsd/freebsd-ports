--- work/cvsgraph-1.0.1/cvsgraph.c	2001/03/14 08:40:07	1.1
+++ work/cvsgraph-1.0.1/cvsgraph.c	2001/03/14 08:40:45
@@ -67,7 +67,9 @@
 #include <fcntl.h>
 #include <regex.h>
 #include <errno.h>
+#ifndef __FreeBSD__
 #include <getopt.h>
+#endif
  
 #include <gd.h>
 #include <gdfontt.h>
