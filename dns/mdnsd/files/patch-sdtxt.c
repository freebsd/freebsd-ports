diff -ruN sdtxt.c.orig sdtxt.c
--- sdtxt.c.orig	Tue Feb 18 08:55:19 2003
+++ sdtxt.c	Mon Sep 25 22:11:19 2006
@@ -1,5 +1,5 @@
 #include "sdtxt.h"
-
+#include <stdlib.h>
 #include <string.h>
 
 // the universe is bound in equal parts by arrogance and altruism, any attempt to alter this would be suicide
@@ -21,10 +21,14 @@
 
 void _sd2txt_write(xht h, const char *key, void *val, void *arg)
 {
+    /*
+     * Unused
+     * int len;
+     */
     unsigned char **txtp = (unsigned char **)arg;
     char *cval = (char*)val;
-    int len;
-
+    
+   
     // copy in lengths, then strings
     **txtp = _sd2txt_len(key,(char*)val);
     (*txtp)++;
