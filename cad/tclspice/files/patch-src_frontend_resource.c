--- src/frontend/resource.c.orig	Sat Jun 24 04:53:17 2006
+++ src/frontend/resource.c	Sat Jun 24 04:55:41 2006
@@ -311,7 +311,7 @@
 static RETSIGTYPE
 fault(void)
 {
-	signal(SIGSEGV, (SIGNAL_FUNCTION) fault);	/* SysV style */
+	signal(SIGBUS, (SIGNAL_FUNCTION) fault);	/* SysV style */
 	siglongjmp(env, 1);
 }
 #if !defined(__MINGW32__) && !defined(__APPLE_CC__)
@@ -321,7 +321,8 @@
 	char *low, *high, *at;
 	/* char *sbrk(int);  */
 	long x;
-	RETSIGTYPE	(*orig_signal)( );
+	RETSIGTYPE	(*orig_sigsegv)( );
+	RETSIGTYPE	(*orig_sigbus)( );
 
 	if (getenv("SPICE_NO_DATASEG_CHECK"))
 		return 0;
@@ -330,7 +331,8 @@
 	low = 0;
 	high = (char *) ((unsigned long) sbrk(0) & ~((1 << LOG2_PAGESIZE) - 1));
 
-	orig_signal = signal(SIGSEGV, (SIGNAL_FUNCTION) fault);
+	orig_sigsegv = signal(SIGSEGV, (SIGNAL_FUNCTION) fault);
+	orig_sigbus = signal(SIGBUS, (SIGNAL_FUNCTION) fault);
 
 	do {
 
@@ -358,7 +360,8 @@
 
 	} while (1);
 
-	(void) signal(SIGSEGV, (SIGNAL_FUNCTION) orig_signal);
+	(void) signal(SIGSEGV, (SIGNAL_FUNCTION) orig_sigsegv);
+	(void) signal(SIGBUS, (SIGNAL_FUNCTION) orig_sigbus);
 	return (void *) high;
 }
 #endif
