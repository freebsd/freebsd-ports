--- setsignals.c.orig	2005-03-29 12:48:21 UTC
+++ setsignals.c
@@ -134,7 +134,7 @@ void blockallsignals() 
     if ( sigaction(SIGTSTP,&sga,0) < 0 ) {
         printmessage(stderr,CASE_FATAL_ERROR,32,timestamp,"Error setting signal SIGTSTP : %s \n",strerror(errno)) ;
     }
-#ifndef DARWIN
+#ifdef SIGPOLL
     if ( sigaction(SIGPOLL,&sga,0) < 0 ) {
         printmessage(stderr,CASE_FATAL_ERROR,32,timestamp,"Error setting signal SIGPOLL : %s \n",strerror(errno)) ;
     }
