Index: src/fetch.c
===================================================================
RCS file: /cvsroot/puf/puf/src/fetch.c,v
retrieving revision 1.29
retrieving revision 1.30
diff -u -r1.29 -r1.30
--- src/fetch.c	1 Jul 2004 13:43:29 -0000	1.29
+++ src/fetch.c	5 Jul 2004 07:41:29 -0000	1.30
@@ -200,6 +200,7 @@
     signal(SIGINT, sigint);
     signal(SIGTERM, sigterm);
     signal(SIGALRM, sigalrm);
+    signal(SIGPIPE, SIG_IGN);
 
     alarm(max_time);
 
