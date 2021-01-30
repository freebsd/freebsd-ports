--- bbftpd_signals.c.orig	2013-02-07 10:46:27 UTC
+++ bbftpd_signals.c
@@ -376,7 +376,7 @@ int bbftpd_blockallsignals() {
         syslog(BBFTPD_ERR,"Error sigaction SIGTSTP : %s",strerror(errno)) ;
         return(-1) ;
     }
-#ifndef DARWIN
+#ifdef SIGPOLL
     if ( sigaction(SIGPOLL,&sga,0) < 0 ) {
         syslog(BBFTPD_ERR,"Error sigaction SIGPOLL : %s",strerror(errno)) ;
         return(-1) ;
