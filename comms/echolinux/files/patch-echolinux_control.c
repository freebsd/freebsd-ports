--- echolinux/control.c.orig	2006-02-24 19:28:15 UTC
+++ echolinux/control.c
@@ -12,6 +12,7 @@ $Log$
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <ctype.h>
 #include <sys/ioctl.h>
 #include <sys/soundcard.h>
 #include <sys/types.h>
@@ -44,7 +45,7 @@ int outControlSocket, inControlSocket;
 int connectTimeout, sdesLength;
 struct hostent *hp;
 char *remoteNode = NULL;
-struct timeval timeout;
+static struct timeval timeout;
 
 int  connected = 0, atemptingConnect = 0, quit = 0;
 pid_t  audioPid;
@@ -130,7 +131,7 @@ int makeConnection(char *host){
       close(audioInPipe[1]);
       close(audioInPipe[0]);
 
-      execlp("echoaudio", "echoaudio", remoteNode, callsign, 0);
+      execlp("echoaudio", "echoaudio", remoteNode, callsign, NULL);
       perror("echoaudio");
       exit(1);
     }
@@ -179,12 +180,12 @@ int makeConnection(char *host){
   connectTimeout = 0;
   timeout.tv_sec = 10;
   timeout.tv_usec = 0;
-
+  return(1);
 }
 
 /**** disconnect from remote node *********/
 
-int disconnect(int sendBye){
+static void disconnect(int sendBye){
 
   int i, length;
   unsigned char *bye;
@@ -258,7 +259,8 @@ void readStdin(void){
 
 int main(int argc, char *argv[]){
 
-  int length, i, len_inet;
+  int length, i;
+  socklen_t len_inet;
   char c, remoteName[40], line[80], *home;
   struct rtcp_sdes_request sdesItems;
 
@@ -277,7 +279,7 @@ int main(int argc, char *argv[]){
   strcat(line, "/.echoLinux/userdata.txt");
   userData = fopen(line, "r");
   if(userData == NULL){
-	  userData = fopen("/etc/echolinux/userdata.txt", "r");
+	  userData = fopen("%%LOCALBASE%%/etc/echolinux/userdata.txt", "r");
 	  if(userData == NULL){
 	    perror("userData");
 	    exit(1);
