--- diskbench.c.orig	2000-07-31 10:24:10.000000000 -0700
+++ diskbench.c	2010-11-23 14:20:52.000000000 -0800
@@ -103,7 +103,7 @@
   return i;
 }
 /*****************************************************************************/
-int diskbench()
+int diskbench(int diskbench_time)
 {
   int sv[2],i;
   int d=0;
@@ -115,7 +115,7 @@
       return 0;
     }
   cpu_score=0;
-  alarm(DISKBENCH_TIME);
+  alarm(diskbench_time);
   switch ( (i=sigsetjmp(env,0xffff)) )
     {
       case 0:
@@ -124,7 +124,7 @@
         for (i=0;i<child_number;i++) kill(child_pid[i],SIGALRM);
         if ( child ) exit(0);
 	close(sv[0]);
-        dlt=(double )cpu_score*(double )itim;
+        dlt=(double )cpu_score * DISKBENCH_TIME * (double )itim / diskbench_time;
         dlt=dlt/(double )DISKREFSCORE;
         cpu_score=dlt;
 	fprintf(stdout,"Ubench DISK: %d\n",cpu_score);
@@ -140,13 +140,13 @@
   itim=diskcalibrate(DISKREFTIME);
   if ( ONEflag )
     {
-      dlt=itim*(double )DISKBENCH_TIME/(double )DISKREFTIME/(double )DISKREFSCORE;
+      dlt=itim*(double )diskbench_time/(double )DISKREFTIME/(double )DISKREFSCORE;
       cpu_score=dlt;
       fprintf(stdout,"Ubench Single DISK: %d (%.2fs)\n",
 	      cpu_score,diskload(itim));
       return cpu_score;
     }
-  alarm(DISKBENCH_TIME);
+  alarm(diskbench_time);
   child_pid[child_number]=fork();
   if ( child_pid[child_number] == -1 )
     {
