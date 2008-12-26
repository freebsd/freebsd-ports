--- uftpd.c.orig	2008-12-26 16:54:54.000000000 +0300
+++ uftpd.c	2008-12-26 16:55:36.000000000 +0300
@@ -200,7 +200,7 @@
       i++;
     }
     if (!found) {
-      logfunc(applog,0,1,0,0,"Name not in host list for id %08lX",header->tx_id);
+      logfunc(applog,0,1,0,0,"Name not in host list for id %08X",header->tx_id);
       return;
     }
   }
@@ -251,11 +251,11 @@
   t=time(NULL);
   logfunc(applog,id_list[listindex].txID,0,0,0,"Received request at %s",ctime(&t));
   if (noname) {
-    logfunc(applog,id_list[listindex].txID,1,0,0,"Request from %s id %08lX",inet_ntoa(id_list[listindex].dest.sin_addr),id_list[listindex].txID);
+    logfunc(applog,id_list[listindex].txID,1,0,0,"Request from %s id %08X",inet_ntoa(id_list[listindex].dest.sin_addr),id_list[listindex].txID);
   } else if ((hp=gethostbyaddr((char *)&(id_list[listindex].dest.sin_addr),sizeof(struct in_addr),AF_INET))) {
-    logfunc(applog,id_list[listindex].txID,1,0,0,"Request from %s (%s) id %08lX",hp->h_name,inet_ntoa(id_list[listindex].dest.sin_addr),id_list[listindex].txID);
+    logfunc(applog,id_list[listindex].txID,1,0,0,"Request from %s (%s) id %08X",hp->h_name,inet_ntoa(id_list[listindex].dest.sin_addr),id_list[listindex].txID);
   } else {
-    logfunc(applog,id_list[listindex].txID,1,0,0,"Request from %s id %08lX",inet_ntoa(id_list[listindex].dest.sin_addr),id_list[listindex].txID);
+    logfunc(applog,id_list[listindex].txID,1,0,0,"Request from %s id %08X",inet_ntoa(id_list[listindex].dest.sin_addr),id_list[listindex].txID);
   }
   logfunc(applog,id_list[listindex].txID,1,0,0,"Name of file to receive: %s",id_list[listindex].filename);
   if (sizeof(f_offset_t)>4)
@@ -644,7 +644,7 @@
           }
         } else {
           if (listindex==-1) {
-            /*logfunc(applog,0,1,0,0,"Invalid txID: %08lX, doesn't match any current file",header->tx_id);*/
+            /*logfunc(applog,0,1,0,0,"Invalid txID: %08X, doesn't match any current file",header->tx_id);*/
             continue;
           }
           switch (id_list[listindex].phase) {
@@ -867,9 +867,9 @@
   applog=stderr;
   nice(-20);
   for (c=1;c<=17;c++)
-    sigset(c,gotsig);
-  sigset(SIGPIPE,gotpipe);
-  sigset(SIGCHLD,SIG_IGN);
+    signal(c,gotsig);
+  signal(SIGPIPE,gotpipe);
+  signal(SIGCHLD,SIG_IGN);
 #endif
   for (c=0;c<MAXLIST;c++)
     id_list[c].txID=0;
