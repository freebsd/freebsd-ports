
$FreeBSD$

--- gltron.c.orig	Sun Apr 15 16:23:13 2001
+++ gltron.c	Fri Apr 27 21:33:07 2001
@@ -3,6 +3,8 @@
   Copyright (C) 1999 by Andreas Umbach <marvin@dataway.ch>
 */
 
+#include <unistd.h>
+
 #include "gltron.h"
 
 /* todo: define the globals where I need them */
@@ -98,7 +100,11 @@
   SystemInit(&argc, argv);
 
 #ifndef CURRENT_EQ_DATA_DIR
-  goto_installpath(argv[0]);
+/*  goto_installpath(argv[0]);*/
+  if (chdir(PREFIX "/share/gltron") != 0) {
+    fprintf(stderr, "gltron: can't chdir into data directory");
+    exit(1);
+  }
 #endif
 
   /* initialize artpack list before loading settigns! */
