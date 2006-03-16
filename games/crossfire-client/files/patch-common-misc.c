--- common/misc.c.orig	Wed Feb  1 19:15:57 2006
+++ common/misc.c	Wed Feb  1 19:16:21 2006
@@ -237,11 +237,11 @@
 #ifndef WIN32
     ChildProcess* cp=FirstChild;
     ChildProcess* last=NULL;
+    ChildProcess* next;
     for (;;){
         if (!cp)
             return; /*no child to monitor*/
         if (waitpid(cp->pid,NULL,WNOHANG)){
-            ChildProcess* next;
 
             /*pid is dead*/
             LOG(LOG_INFO,"common::monitorChilds","Child %s died. Removing and closing pipes",cp->name?cp->name:"UNKNOWN");
