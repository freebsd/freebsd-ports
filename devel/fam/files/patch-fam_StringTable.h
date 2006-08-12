--- fam/StringTable.h.orig	Fri Aug 11 22:29:55 2006
+++ fam/StringTable.h	Fri Aug 11 22:30:12 2006
@@ -25,6 +25,7 @@
 
 #include <assert.h>
 #include <string.h>
+#include "mntent.h"
 
 //  A StringTable maps C strings onto values.  It is a cheap O(n)
 //  implementation, suitable only for small tables that are
