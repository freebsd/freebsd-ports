--- hfkernel/mt63/mt63tx.cc.orig	Sun Jul 30 11:47:07 2006
+++ hfkernel/mt63/mt63tx.cc	Sun Jul 30 11:47:26 2006
@@ -31,6 +31,9 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <ctype.h>
+#ifdef __FreeBSD__ 
+#include <unistd.h>
+#endif
 
 #include "dsp.h"
 #include "mt63.h"
