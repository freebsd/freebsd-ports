--- src/topology/parser.c.orig	2015-11-09 07:39:18 UTC
+++ src/topology/parser.c
@@ -18,6 +18,7 @@
 
 #include "list.h"
 #include "tplg_local.h"
+#include <sys/stat.h>
 
 /*
  * Parse compound
