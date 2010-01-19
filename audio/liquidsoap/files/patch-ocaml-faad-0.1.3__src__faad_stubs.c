--- ./ocaml-faad-0.1.3/src/faad_stubs.c.orig	2009-10-30 16:07:44.000000000 +0200
+++ ./ocaml-faad-0.1.3/src/faad_stubs.c	2009-12-11 21:42:25.000000000 +0200
@@ -40,6 +40,7 @@
 #include <stdio.h>
 
 #include <neaacdec.h>
+#include "config.h"
 #include <mp4ff.h>
 
 static void check_err(int n)
