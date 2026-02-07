--- echogui/threadFuncs.c.orig	2004-02-03 02:28:03 UTC
+++ echogui/threadFuncs.c
@@ -1,5 +1,6 @@
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <pthread.h>
 #include <signal.h>
 
@@ -47,7 +48,7 @@ void destroyApp(void){
 void sigHandler(int sig){
 
   // puts("In signal handler");
-  if(sig = SIGINT){
+  if(sig == SIGINT){
     // puts("It is a SIGINT");
     destroyApp();
     exit(0);
