--- Poll/poll.c.orig	Mon Jul 29 01:35:10 2002
+++ Poll/poll.c	Sun Jan 26 10:59:31 2003
@@ -26,7 +26,7 @@
    
    
    /*signal(SIGCLD, SIG_IGN);*/
-   signal(SIGCLD, parent_terminate);  
+   signal(SIGCHLD, parent_terminate);  
    
    /*printf("pid des Prozesses = %d, Parent-pid des Prozesses = %d\n\n",getpid(), getppid());*/
    
