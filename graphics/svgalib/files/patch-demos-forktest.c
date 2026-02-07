--- demos/forktest.c.orig	Fri Aug 25 06:13:58 2000
+++ demos/forktest.c	Fri Aug 25 06:14:15 2000
@@ -18,7 +18,7 @@
  SIGTRAP, SIGIOT, SIGBUS, SIGFPE,
  SIGSEGV, SIGPIPE, SIGALRM, SIGTERM,
  SIGXCPU, SIGXFSZ, SIGVTALRM,
- SIGPROF, SIGPWR};
+ SIGPROF, SIGUSR1};
 
 
 static int newcolor(void)
