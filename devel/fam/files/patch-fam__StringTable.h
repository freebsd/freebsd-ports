--- ./fam/StringTable.h.orig	2003-04-15 06:21:43.000000000 +0200
+++ ./fam/StringTable.h	2014-01-03 02:35:10.000000000 +0100
@@ -25,6 +25,7 @@
 
 #include <assert.h>
 #include <string.h>
+#include "mntent.h"
 
 //  A StringTable maps C strings onto values.  It is a cheap O(n)
 //  implementation, suitable only for small tables that are
