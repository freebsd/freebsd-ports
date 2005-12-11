--- src/frontend/resource.c.orig	Thu Jun 30 23:38:21 2005
+++ src/frontend/resource.c	Sat Dec 10 20:41:22 2005
@@ -424,6 +424,7 @@
 fault(void)
 {
 	signal(SIGSEGV, (SIGNAL_FUNCTION) fault);	/* SysV style */
+	signal(SIGBUS, (SIGNAL_FUNCTION) fault);	/* SysV style */
 	LONGJMP(env, 1);
 }
 
@@ -436,7 +437,8 @@
 	char *low, *high, *at;
 	/* char *sbrk(int);  */
 	long x;
-	RETSIGTYPE	(*orig_signal)( );
+	RETSIGTYPE	(*orig_sigsegv)( );
+	RETSIGTYPE	(*orig_sigbus)( );
 
 	if (getenv("SPICE_NO_DATASEG_CHECK"))
 		return 0;
@@ -444,7 +446,8 @@
 	low = 0;
 	high = (char *) ((unsigned long) sbrk(0) & ~((1 << LOG2_PAGESIZE) - 1));
 
-	orig_signal = signal(SIGSEGV, (SIGNAL_FUNCTION) fault);
+	orig_sigsegv = signal(SIGSEGV, (SIGNAL_FUNCTION) fault);
+	orig_sigbus = signal(SIGBUS, (SIGNAL_FUNCTION) fault);
 
 	do {
 
@@ -472,7 +475,8 @@
 
 	} while (1);
 
-	(void) signal(SIGSEGV, (SIGNAL_FUNCTION) orig_signal);
+	(void) signal(SIGSEGV, (SIGNAL_FUNCTION) orig_sigsegv);
+	(void) signal(SIGBUS, (SIGNAL_FUNCTION) orig_sigbus);
 	return (void *) high;
 
 #endif
