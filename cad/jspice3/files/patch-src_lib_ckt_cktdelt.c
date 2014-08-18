--- src/lib/ckt/cktdelt.c.orig	1997-03-21 22:04:30.000000000 +0000
+++ src/lib/ckt/cktdelt.c
@@ -20,7 +20,7 @@ GENERIC *task;
 {
     JOB *job, *next;
 
-    if (task == NULL) return;
+    if (task == NULL) return (OK);
 
     for (job = ((TSKtask*)task)->jobs; job; job = next) {
         next = job->JOBnextJob;
