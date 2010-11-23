--- netbench.c.orig	2000-02-18 14:39:30.000000000 -0800
+++ netbench.c	2010-11-23 14:20:52.000000000 -0800
@@ -18,7 +18,7 @@
  */
 
 extern int NETflag;
-int netbench()
+int netbench(int netbench_time)
 {
   NETflag = 0;
   return 0;
