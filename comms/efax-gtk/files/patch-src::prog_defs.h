--- src/prog_defs.h.orig	Mon May  3 16:44:33 2004
+++ src/prog_defs.h	Mon May  3 16:44:46 2004
@@ -9,6 +9,8 @@
 #ifndef PROG_DEFS_H
 #define PROG_DEFS_H
 
+#include <unistd.h>
+
 #include "config.h"
 
 // deal with any configuration issues arising from config.h
