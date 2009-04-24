--- src/daemon/main.c.orig	2009-01-12 18:11:38.000000000 -0500
+++ src/daemon/main.c	2009-03-07 19:56:16.000000000 -0500
@@ -37,6 +37,7 @@
 #include <unistd.h>
 #include <locale.h>
 #include <sys/types.h>
+#include <sys/stat.h>
 
 #include <liboil/liboil.h>
 
