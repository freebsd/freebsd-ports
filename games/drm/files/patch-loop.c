--- loop.c.orig	Fri Dec 15 01:03:06 2006
+++ loop.c	Fri Dec 15 01:04:01 2006
@@ -3,6 +3,8 @@
 struct pos      npos[] = {1, 1,
 			-1, -1}; /*used in turning chips*/
 
+void change(int);
+
 void
 loop()
 {
