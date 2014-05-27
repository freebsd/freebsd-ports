--- onewclient.c.orig	2014-05-25 11:46:28.000000000 +0900
+++ onewclient.c	2014-05-25 11:47:06.000000000 +0900
@@ -43,7 +43,7 @@
 	Onew_message(form,a,b,c,d,e,f,g);
 }
 
-static open_onew(){
+static void open_onew(void){
 	register int pid;
 	char *command;
 
