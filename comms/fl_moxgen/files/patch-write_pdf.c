--- write_pdf.c.orig	2014-04-12 15:29:28.000000000 -0700
+++ write_pdf.c	2014-04-12 15:29:54.000000000 -0700
@@ -6,6 +6,7 @@
 #include <setjmp.h>
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h> // for getcwd()
 #include <sys/stat.h> // for stat()
 
 #include "fl_moxgen_defines.h"
