--- common/misc.c.orig	Sat May  8 15:31:29 2004
+++ common/misc.c	Sat May  8 15:31:49 2004
@@ -237,13 +237,13 @@
 #ifndef WIN32
     ChildProcess* cp=FirstChild;
     ChildProcess* last=NULL;
+    ChildProcess* next;
     for (;;){
         if (!cp)
             return; /*no child to monitor*/
         if (waitpid(cp->pid,NULL,WNOHANG)){
             /*pid is dead*/
             LOG(LOG_INFO,"common::monitorChilds","Child %s died. Removing and closing pipes",cp->name?cp->name:"UNKNOWN");
-            ChildProcess* next;
             if (cp==LastChild)
                 LastChild=last;
             next=cp->next;
