--- sload/symb.c.orig	Wed Oct  3 23:28:21 2007
+++ sload/symb.c	Wed Oct  3 23:28:31 2007
@@ -8,7 +8,7 @@
 #include "sptree.h"
 
 
-static SYMBOLPTR symtree;
+SYMBOLPTR symtree;
 int lookups=0, lkcmps=0, adds=0;
 
 b_16 symbols;
