--- ./src/random/C2LCGXgen.m.orig	Fri Oct 10 05:19:01 2003
+++ ./src/random/C2LCGXgen.m	Fri Oct 10 05:19:10 2003
@@ -152,7 +152,7 @@
   
   if ((A > maxGen) || (v > 60) || (w > 60))
     {
-      printf("Generator parameters: A = %d  v = %d  w = %d
+      printf("Generator parameters: A = %d  v = %d  w = %d \
 maxA = %lu  maxv = 60  maxw = 60\n\n", 
              A,v,w,maxGen);
     [InvalidCombination
