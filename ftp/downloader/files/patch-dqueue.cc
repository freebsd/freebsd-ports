--- main/dqueue.cc.orig	Tue May 28 02:55:12 2002
+++ main/dqueue.cc	Sun Jun 16 08:38:39 2002
@@ -127,7 +127,7 @@
 	};
 };
 
-void d4xDownloadQueue::add(tDownload *what,int where=DL_WAIT){
+void d4xDownloadQueue::add(tDownload *what,int where){
 	if (where==DL_WAIT || where==DL_RUN)
 		RUN_OR_WAIT_DOWNLOADS+=1;
 	queues[where]->insert(what);
