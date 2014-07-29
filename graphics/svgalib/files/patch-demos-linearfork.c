--- demos/linearfork.c.orig	Fri Aug 25 06:14:48 2000
+++ demos/linearfork.c	Fri Aug 25 06:15:00 2000
@@ -18,7 +18,7 @@
  SIGTRAP, SIGIOT, SIGBUS, SIGFPE,
  SIGSEGV, SIGPIPE, SIGALRM, SIGTERM,
  SIGXCPU, SIGXFSZ, SIGVTALRM,
- SIGPROF, SIGPWR};
+ SIGPROF, SIGUSR1};
 
 
 static int newcolor(void)
