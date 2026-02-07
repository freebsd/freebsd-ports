--- diskbench.c.orig	2000-07-31 17:24:10 UTC
+++ diskbench.c
@@ -103,7 +103,7 @@ double cdt;
   return i;
 }
 /*****************************************************************************/
-int diskbench()
+int diskbench(int diskbench_time)
 {
   int sv[2],i;
   int d=0;
@@ -115,7 +115,7 @@ int diskbench()
       return 0;
     }
   cpu_score=0;
-  alarm(DISKBENCH_TIME);
+  alarm(diskbench_time);
   switch ( (i=sigsetjmp(env,0xffff)) )
     {
       case 0:
@@ -124,7 +124,7 @@ int diskbench()
         for (i=0;i<child_number;i++) kill(child_pid[i],SIGALRM);
         if ( child ) exit(0);
 	close(sv[0]);
-        dlt=(double )cpu_score*(double )itim;
+        dlt=(double )cpu_score * DISKBENCH_TIME * (double )itim / diskbench_time;
         dlt=dlt/(double )DISKREFSCORE;
         cpu_score=dlt;
 	fprintf(stdout,"Ubench DISK: %d\n",cpu_score);
@@ -140,13 +140,13 @@ int diskbench()
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
