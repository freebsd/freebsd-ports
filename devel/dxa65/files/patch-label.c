--- label.c.orig	2006-11-01 18:23:28.000000000 +0200
+++ label.c	2010-08-31 21:45:43.000000000 +0300
@@ -40,7 +40,7 @@
 #include "opcodes.h"
 
 label *labeltable;
-char defaultlabel[5];
+char defaultlabel[6];
 unsigned numLabels = 0;
 
 #ifndef __STDC__
@@ -55,7 +55,7 @@
   label *entry;
   char *buffer;
 
-  if (!((buffer = malloc (strlen (name)))))
+  if (!((buffer = malloc (strlen (name) + 1))))
     return;
 
   entry = numLabels ?

