diff -ruN fam/StringTable.h fam/StringTable.h
--- fam/StringTable.h	Mon Apr 29 02:26:54 2002
+++ fam/StringTable.h	Sat Jun  8 16:31:07 2002
@@ -25,6 +25,7 @@
 
 #include <assert.h>
 #include <string.h>
+#include "mntent.h"
 
 //  A StringTable maps C strings onto values.  It is a cheap O(n)
 //  implementation, suitable only for small tables that are
