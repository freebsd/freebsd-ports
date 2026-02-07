--- netbench.c.orig	2000-02-18 22:39:30 UTC
+++ netbench.c
@@ -18,7 +18,7 @@
  */
 
 extern int NETflag;
-int netbench()
+int netbench(int netbench_time)
 {
   NETflag = 0;
   return 0;
