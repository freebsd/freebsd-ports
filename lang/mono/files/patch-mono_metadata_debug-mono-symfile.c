--- mono/metadata/debug-mono-symfile.c.orig	Thu Dec 26 12:33:21 2002
+++ mono/metadata/debug-mono-symfile.c	Thu Dec 26 12:33:57 2002
@@ -2,6 +2,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <signal.h>
+#include <sys/param.h>
 #include <mono/metadata/metadata.h>
 #include <mono/metadata/tabledefs.h>
 #include <mono/metadata/rawbuffer.h>
