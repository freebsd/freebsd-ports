--- label.c.orig	2006-11-01 16:23:28 UTC
+++ label.c
@@ -40,7 +40,7 @@
 #include "opcodes.h"
 
 label *labeltable;
-char defaultlabel[5];
+char defaultlabel[6];
 unsigned numLabels = 0;
 
 #ifndef __STDC__
@@ -55,7 +55,7 @@ void AddLabel (ADDR_T address, char *nam
   label *entry;
   char *buffer;
 
-  if (!((buffer = malloc (strlen (name)))))
+  if (!((buffer = malloc (strlen (name) + 1))))
     return;
 
   entry = numLabels ?
