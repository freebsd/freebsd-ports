--- file-io.c.orig	Mon Aug 12 15:30:44 2002
+++ file-io.c	Mon Aug 12 15:30:55 2002
@@ -1,6 +1,7 @@
 /* the functions to read and write fractal calculations to a file */
 
 #include "deep_zoom.h"
+#include <cstring>
 
 // writes an mpf_t to the file as the overall information followed by the data
 
