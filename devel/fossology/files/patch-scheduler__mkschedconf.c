--- scheduler/mkschedconf.c.orig	2009-07-09 23:04:45.000000000 +0000
+++ scheduler/mkschedconf.c	2009-07-14 01:45:35.000000000 +0000
@@ -180,14 +180,14 @@
   /** fosscp **/
   fprintf(Fout,"agent=fosscp_agent %s| ",CmdHost);
   memset(Cmd,'\0',sizeof(Cmd));
-  snprintf(Cmd,sizeof(Cmd)-1,Rcmd,"%s/engine-shell fosscp_agent '%s/cp2foss %{*}'");
+  snprintf(Cmd,sizeof(Cmd)-1,Rcmd,"%s/engine-shell fosscp_agent '%s/cp2foss %%{*}'");
   fprintf(Fout,Cmd,AGENTDIR,BINDIR);
   fprintf(Fout,"\n");
 
  /** notify **/
   fprintf(Fout,"agent=fo_notify %s| ",CmdHost);
   memset(Cmd,'\0',sizeof(Cmd));
-  snprintf(Cmd,sizeof(Cmd)-1,Rcmd,"%s/engine-shell fo_notify '%s/fo_notify %{*}'");
+  snprintf(Cmd,sizeof(Cmd)-1,Rcmd,"%s/engine-shell fo_notify '%s/fo_notify %%{*}'");
   fprintf(Fout,Cmd,AGENTDIR,BINDIR);
   fprintf(Fout,"\n");
 
