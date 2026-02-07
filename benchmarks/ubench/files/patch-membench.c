--- membench.c.orig	2000-07-31 17:23:27 UTC
+++ membench.c
@@ -102,7 +102,7 @@ double cdt;
   return i;
 }
 /*****************************************************************************/
-int membench()
+int membench(int membench_time)
 {
   int sv[2],i;
   int d=0;
@@ -114,7 +114,7 @@ int membench()
       return 0;
     }
   cpu_score=0;
-  alarm(MEMBENCH_TIME);
+  alarm(membench_time);
   switch ( (i=sigsetjmp(env,0xffff)) )
     {
       case 0:
@@ -123,7 +123,7 @@ int membench()
         for (i=0;i<child_number;i++) kill(child_pid[i],SIGALRM);
         if ( child ) exit(0);
 	close(sv[0]);
-        dlt=(double )cpu_score*(double )itim;
+        dlt=(double )cpu_score * MEMBENCH_TIME * (double )itim / membench_time;
         dlt=dlt/(double )MEMREFSCORE;
         cpu_score=dlt;
 	fprintf(stdout,"Ubench MEM: %8d\n",cpu_score);
@@ -139,13 +139,13 @@ int membench()
   itim=memcalibrate(MEMREFTIME);
   if ( ONEflag )
     {
-      dlt=itim*(double )MEMBENCH_TIME/(double )MEMREFTIME/(double )MEMREFSCORE;
+      dlt=itim*(double )membench_time/(double )MEMREFTIME/(double )MEMREFSCORE;
       cpu_score=dlt;
       fprintf(stdout,"Ubench Single MEM: %8d (%.2fs)\n",
 	      cpu_score,memload(itim));
       return cpu_score;
     }
-  alarm(MEMBENCH_TIME);
+  alarm(membench_time);
   child_pid[child_number]=fork();
   if ( child_pid[child_number] == -1 )
     {
