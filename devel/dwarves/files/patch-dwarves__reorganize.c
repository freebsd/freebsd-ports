--- dwarves_reorganize.c.orig	2024-10-04 17:48:24 UTC
+++ dwarves_reorganize.c
@@ -7,9 +7,9 @@
   Copyright (C) 2007 Arnaldo Carvalho de Melo <acme@redhat.com>
 */
 
-#include "list.h"
 #include "dwarves_reorganize.h"
 #include "dwarves.h"
+#include "list.h"
 
 static void class__recalc_holes(struct class *class)
 {
