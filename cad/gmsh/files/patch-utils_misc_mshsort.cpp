--- utils/misc/mshsort.cpp.orig	2008-12-29 10:43:51.000000000 +0100
+++ utils/misc/mshsort.cpp	2009-02-04 10:41:41.000000000 +0100
@@ -6,8 +6,9 @@
 // A small utility that reads a Gmsh mesh file and makes the numbering
 // dense (without gaps in the node/element number sequences)
 
+#include <stdlib.h>
 #include <stdio.h>
-#include <strings.h>
+#include <string.h>
 #include <vector>
 #include <map>
 
