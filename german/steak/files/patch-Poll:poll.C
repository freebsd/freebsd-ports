--- Poll/poll.C.orig	Tue Jan  4 03:11:05 2000
+++ Poll/poll.C	Sun Jan 26 11:00:13 2003
@@ -27,7 +27,7 @@
    
    
    //signal(SIGCLD, SIG_IGN);
-   signal(SIGCLD, parent_terminate);  
+   signal(SIGCHLD, parent_terminate);  
    
    //printf("pid des Prozesses = %d, Parent-pid des Prozesses = %d\n\n",getpid(), getppid());
    
