--- sim/mempool.c.orig	2007-11-23 22:23:58.000000000 +0100
+++ sim/mempool.c	2007-11-23 22:24:10.000000000 +0100
@@ -23,7 +23,6 @@
 #include "mempool.h"
 
 extern char *sim_calloc(), *sim_malloc();
-#define NULL 0
 #define TRUE 1
 #define FALSE 0
 
