--- src/vehicle.c.orig	2023-04-13 00:36:40 UTC
+++ src/vehicle.c
@@ -58,6 +58,8 @@
 
 #define SIGN(d)  ((d)>=0.0? 1.0:-1.0)
 
+extern struct _GrBreakData GrBreak;
+
 static void
 next_word (char *str, int *index)
 {
