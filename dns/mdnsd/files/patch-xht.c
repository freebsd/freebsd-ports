diff -ruN xht.c.orig xht.c
--- xht.c.orig	Tue Feb 18 08:57:07 2003
+++ xht.c	Mon Sep 25 22:11:20 2006
@@ -1,4 +1,6 @@
 #include "xht.h"
+#include <stdlib.h>
+#include <string.h>
 
 typedef struct xhn_struct
 {
@@ -83,13 +85,15 @@
     /* when flag is set, we manage their mem and free em first */
     if(n->flag)
     {
-        free(n->key);
+        free((void *)n->key);
         free(n->val);
     }
 
     n->flag = flag;
     n->key = key;
     n->val = val;
+
+    return NULL;
 }
 
 void xht_set(xht h, const char *key, void *val)
@@ -140,7 +144,7 @@
             f = n->next;
             if(n->flag)
             {
-                free(n->key);
+                free((void *)n->key);
                 free(n->val);
             }
             free(n);
