--- tune.c.orig	Tue May 18 09:43:30 2004
+++ tune.c	Fri Jul  9 12:25:02 2004
@@ -1,10 +1,9 @@
 
-
-#include <sys/io.h>
+#include <sys/types.h>
 #include <vga.h>
 #include <vgagl.h>
 #include <unistd.h>
-
+#include <machine/cpufunc.h>
 #include "globdef.h"
 #include "uidef.h"
 #include "fft1def.h"
