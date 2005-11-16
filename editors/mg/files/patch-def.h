diff -u -x _darcs -ur _darcs/current/def.h ./def.h
--- _darcs/current/def.h	Tue Jun 14 20:14:40 2005
+++ ./def.h	Sun Aug 21 02:30:50 2005
@@ -3,6 +3,7 @@
 /* This file is in the public domain. */
 
 #include <sys/queue.h>
+#include "queue.h"
 
 /*
  * This file is the general header file for all parts
