
$FreeBSD$

--- ./main.c.orig	Mon May 19 15:44:41 2003
+++ ./main.c	Mon May 19 15:55:24 2003
@@ -35,11 +35,14 @@
 int main(int argc, char **argv)
 {
   char cmd[1];
+  int repetivity;
   fd_set rset;
   struct timeval stime;
 
   /* Parse arguments */
-  cd_device=DEVICE;
+  cd_device=getenv("CDROM");
+  if (cd_device==NULL)
+    cd_device=DEVICE;
   if(argc>1 && !strcmp(argv[1],"-d"))
     cd_device=argv[2];
   else if(argc>1)
@@ -68,19 +71,20 @@
 
   while(1){
     if(select(1,&rset,(fd_set *) 0,(fd_set *) 0,&stime)>0) {
-      read(STDIN_FILENO,cmd,FD_SETSIZE);
-      
+      getcommand(&cmd[0], &repetivity);
+
       if(cmd[0]=='p'){message="play";play_track(1);}
       else if(cmd[0]=='F'){message="next";next();}
       else if(cmd[0]=='R'){message="prev";prev();}
-      else if(cmd[0]=='f'){message="ff";ff();}
-      else if(cmd[0]=='r'){message="rew";rew();}
+      else if(cmd[0]=='f'){message="ff";ff(repetivity);}
+      else if(cmd[0]=='r'){message="rew";rew(repetivity);}
       else if(cmd[0]=='s'){message="stop";stop();}
-      else if(cmd[0]=='e'){message="eject";eject();}
-      else if(cmd[0]==' ') cdpause();
+      else if(cmd[0]=='E'){message="eject";eject();}
+      else if(cmd[0]==' ') cdsoftpause();
       else if(cmd[0]=='+'){message="more vol";more_vol();}
       else if(cmd[0]=='-'){message="less vol";less_vol();}
       else if(cmd[0]=='q'){message="bye!";do_exit(0);}
+      else if(cmd[0]=='P') cdpause();
     }
     update_cdinfo();
     move_up(5);
@@ -90,6 +94,36 @@
   }
     
     exit(0);
+}
+
+void getcommand(char *command, int *repetivity)
+{
+  static char stored_command;
+  int n;
+
+  fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
+
+  if (stored_command) {
+    *command=stored_command;
+  } else {
+    n=read(STDIN_FILENO,command,1);
+    if (n <= 0) {
+      *command='\0';
+      *repetivity=0;
+      return;
+    }
+  }
+
+  *repetivity=1;
+  while (read(STDIN_FILENO, &stored_command, 1) > 0) {
+    if (stored_command == *command) {
+      (*repetivity)++;
+    } else {
+      return;
+    }
+  }
+  stored_command='\0';
+  return;
 }
 
 void hs_cont(void)
