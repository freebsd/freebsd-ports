--- mysys/my_symlink.c.orig	2017-07-19 12:10:42 UTC
+++ mysys/my_symlink.c
@@ -23,6 +23,7 @@
 #include <sys/param.h>
 #include <sys/stat.h>
 #endif
+#include "my_dir.h"
 
 /*
   Reads the content of a symbolic link
