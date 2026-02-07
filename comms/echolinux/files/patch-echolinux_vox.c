--- echolinux/vox.c.orig	2006-03-03 23:43:05 UTC
+++ echolinux/vox.c
@@ -14,7 +14,7 @@ $Log$
 #include <stdlib.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
@@ -70,7 +70,7 @@ int mode;
 
 /**************** read info file ***********/
 
-int sendInfoFile(void){
+static int sendInfoFile(void){
   int count = 0, result;
   char *temp, line[80];
 
@@ -79,7 +79,7 @@ int sendInfoFile(void){
 
   infoFile = open(line, O_RDONLY);
   if(infoFile < 0){
-	  infoFile = open("/etc/echolinux/info.txt", O_RDONLY);
+	  infoFile = open("%%LOCALBASE%%/etc/echolinux/info.txt", O_RDONLY);
 	  if(infoFile < 0){
 	    perror("Openning info file.");
 	    return(FALSE);
@@ -129,12 +129,12 @@ int sendInfoFile(void){
 		  (struct sockaddr *) &destAddr,
 		  sizeof destAddr);
   
-  
+  return(TRUE); 
 }
 
 /****************************************/
 
-int soundInput(void){
+static void soundInput(void){
 
   // int arg, status;
   int arg, status;
@@ -242,7 +242,7 @@ void sendNDATA(char *ndata){
 
 /**************** Handle data from stdin ***********/
 
-int fromControl(void){
+static void fromControl(void){
   int i;
   char c;
   char line[80], fileName[80], globalFileName[80];
@@ -260,7 +260,7 @@ int fromControl(void){
     strcpy(fileName, echoLinuxDefaults);
     line[strlen(line) - 1] = 0x00;
     strcat(fileName, &line[2]);
-	strcpy(globalFileName, "/etc/echolinux/");
+	strcpy(globalFileName, "%%LOCALBASE%%/etc/echolinux/");
 	strcat(globalFileName, &line[2]);
     //      strcat(fileName, "connect.wav");
     if(((audioEffect = open(fileName, O_RDONLY)) != -1) || (audioEffect = open(globalFileName, O_RDONLY)) != -1){
@@ -305,14 +305,14 @@ int fromControl(void){
 
 /******************* Audio sending routine **************/
 
-int sendAudio(void){
+static void sendAudio(void){
 
   static short seq = 1;
   short count = 0, total = 0;
   short i, result, *pTemp, j;
   char c, *temp, line[20];
   fd_set readfds, testfds;
-  int len_inet;
+  socklen_t len_inet;
   //   struct timeval timeout;
   time_t  startTime, timeNow;
   long average;
@@ -399,7 +399,7 @@ int sendAudio(void){
 	}
       }
       if(sendStrength){
-	sprintf(line, "%C %d", STRENGTH, average);
+	sprintf(line, "%C %ld", STRENGTH, average);
 	puts(line);
       }
 
@@ -477,11 +477,11 @@ int sendAudio(void){
 
 /************ Audio Receiving Function *******/
 
-int recvAudio(void){
+static void recvAudio(void){
   struct gsmVoice_t *voicePacket;
   fd_set readfds, testfds;
   short i, result, j, *pTemp;
-  int len_inet;
+  socklen_t len_inet;
   audio_buf_info info;
   unsigned char *temp;
   char c, line[20];
@@ -559,7 +559,7 @@ int recvAudio(void){
 	  }
 	  average = average / 320;
 	  if(sendStrength){
-	    sprintf(line, "%C %d", STRENGTH, average);
+	    sprintf(line, "%C %ld", STRENGTH, average);
 	    puts(line);
 	  }
 	}
