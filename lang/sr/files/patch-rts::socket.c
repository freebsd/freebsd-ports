--- rts/socket.c.orig	Tue Jun 10 20:36:37 2003
+++ rts/socket.c	Tue Jun 10 20:36:53 2003
@@ -482,7 +482,9 @@
 char *message;
 {
     char s1[100], s2[100];
+/*
     extern int sys_nerr;
+*/
 
 #if !defined(__NetBSD__) && !defined(__FreeBSD__)
     extern char *sys_errlist[];
