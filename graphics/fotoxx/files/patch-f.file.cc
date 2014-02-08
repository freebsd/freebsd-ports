--- ./f.file.cc.orig	2014-02-05 20:42:34.000000000 +0100
+++ ./f.file.cc	2014-02-06 10:32:37.000000000 +0100
@@ -23,6 +23,7 @@
 
 #define EX extern                                                          //  disable extern declarations
 #include "fotoxx.h"
+#include <sys/wait.h>
 
 /**************************************************************************
       Fotoxx image edit - file menu functions
