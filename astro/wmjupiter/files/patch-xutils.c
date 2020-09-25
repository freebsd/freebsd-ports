--- xutils.c.orig	2015-12-06 02:51:22 UTC
+++ xutils.c
@@ -40,6 +40,16 @@
 #include "xutils.h"
 
 
+/*
+ *   Global variable
+ */
+Display		*display;
+Window		Root;
+Window		iconwin, win;
+int		screen; 
+int		DisplayDepth;
+GC		NormalGC;
+
 
 /*
  *   X11 Variables 
