--- cpubench.c.orig	2000-05-29 03:21:13 UTC
+++ cpubench.c
@@ -114,7 +114,7 @@ double cdt;
   return i;
 }
 /*****************************************************************************/
-int cpubench()
+int cpubench(int cpubench_time)
 {
   int sv[2],i;
   int d=0;
@@ -126,7 +126,7 @@ int cpubench()
       return 0;
     }
   cpu_score=0;
-  alarm(CPUBENCH_TIME);
+  alarm(cpubench_time);
   switch ( (i=sigsetjmp(env,0xffff)) )
     {
       case 0:
@@ -136,7 +136,7 @@ int cpubench()
         if ( child ) exit(0);
         child_number=0;
 	close(sv[0]);
-        dlt=(double )cpu_score*(double )itim;
+        dlt=(double )cpu_score * CPUBENCH_TIME * (double )itim / cpubench_time;
         dlt=dlt/(double )CPUREFSCORE;
         cpu_score=dlt;
 	fprintf(stdout,"Ubench CPU: %8d\n",cpu_score);
@@ -152,13 +152,13 @@ int cpubench()
   itim=cpucalibrate(CPUREFTIME);
   if ( ONEflag )
     {
-      dlt=itim*(double )CPUBENCH_TIME/(double )CPUREFTIME/(double )CPUREFSCORE;
+      dlt=itim*(double )cpubench_time/(double )CPUREFTIME/(double )CPUREFSCORE;
       cpu_score=dlt;
       fprintf(stdout,"Ubench Single CPU: %8d (%.2fs)\n",
 	      cpu_score,cpuload(itim));
       return cpu_score;
     }
-  alarm(CPUBENCH_TIME);
+  alarm(cpubench_time);
   child_pid[child_number]=fork();
   if ( child_pid[child_number] == -1 )
     {
