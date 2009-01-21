$FreeBSD$

--- src/grads.h.orig	2009-01-20 21:06:54.000000000 -0800
+++ src/grads.h	2009-01-20 21:07:06.000000000 -0800
@@ -11,6 +11,7 @@
 
 /* kk 020624 --- change for 64bit seek K.Komine mf */
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <gabufr.h>
