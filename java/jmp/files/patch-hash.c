$FreeBSD$

--- hash.c	Thu Jun 26 16:23:50 2003
+++ hash.c	Thu Jun 26 16:23:20 2003
@@ -1,7 +1,7 @@
 /* Handle a hash table.
  */
 
-#include <malloc.h>
+#include <stdlib.h>
 #include <jmp.h>
 
 struct hashnode
