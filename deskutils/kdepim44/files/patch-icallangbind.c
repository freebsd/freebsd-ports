--- libical/src/libical/icallangbind.c	Wed Apr 11 15:37:32 2001
+++ libical/src/libical/icallangbind.c.new	Sat Jun  1 05:06:07 2002
@@ -22,7 +22,7 @@
 #include "icalproperty.h"
 #include "icalerror.h"
 #include "icalmemory.h"
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 
 int* icallangbind_new_array(int size){
