--- uftpd.c.orig	2008-12-26 16:54:54.000000000 +0300
+++ uftpd.c	2008-12-26 16:55:36.000000000 +0300
@@ -867,9 +867,9 @@
   applog=stderr;
   nice(-20);
   for (c=1;c<=17;c++)
-    sigset(c,gotsig);
-  sigset(SIGPIPE,gotpipe);
-  sigset(SIGCHLD,SIG_IGN);
+    signal(c,gotsig);
+  signal(SIGPIPE,gotpipe);
+  signal(SIGCHLD,SIG_IGN);
 #endif
   for (c=0;c<MAXLIST;c++)
     id_list[c].txID=0;
