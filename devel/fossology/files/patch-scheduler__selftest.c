--- ./scheduler/selftest.c.orig	2008-11-24 18:15:44.000000000 +0000
+++ ./scheduler/selftest.c	2009-07-10 01:47:07.000000000 +0000
@@ -42,7 +42,7 @@
 {
   FILE *Fin, *FData, *FTest;
   char SelfTest[] = "echo 'test' | " AGENTDIR "/selftest -g -s"; /* -g for generate test data */
-  char MkConfig[] = LIBEXECDIR "/mkschedconf -L 2>&1 | grep agent | sed 's/.*agent=\\(\\w*\\).*/\\1/' | sort -u"; /* get list of agents */
+  char MkConfig[] = LIBEXECDIR "/mkschedconf -L 2>&1 | grep agent | sed 's/.*agent=\\([^[:blank:]]*\\).*/\\1/' | sort -u"; /* get list of agents */
   int c,i;
   int Thread;
   int rc=0;
