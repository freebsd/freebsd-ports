--- lib/direct/conf.c.orig	2007-12-15 14:30:28.000000000 +0200
+++ lib/direct/conf.c	2008-03-16 14:31:28.000000000 +0200
@@ -31,6 +31,8 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <signal.h>
+
 #include <direct/conf.h>
 #include <direct/mem.h>
 #include <direct/util.h>
