--- src/thread.c.orig	Wed Nov  5 22:03:00 1997
+++ src/thread.c	Sun Jan 30 18:09:03 2000
@@ -118,7 +118,7 @@
 	&& scp->sc_pc <= (unsigned long)_ENDMONITOR)
 		return 0;
 	put(current, &ready);
-	sigsetmask(scp->sc_mask);
+	sigprocmask(SIG_SETMASK, NULL, &(scp->sc_mask));
 	run();
 	return 0;
 }
@@ -243,13 +243,13 @@
 		critical--; } while (0);
 		args = t->sp;
 	}
-#if alpha
-	{ extern void _start(void);
+#if __alpha
+	{ extern void _thrstart(void);
 	  t->sp -= 112/8;
 	  t->sp[(48+24)/8] = (unsigned long)Thread_exit;
 	  t->sp[(48+16)/8] = (unsigned long)args;
 	  t->sp[(48+ 8)/8] = (unsigned long)apply;
-	  t->sp[(48+ 0)/8] = (unsigned long)_start; }
+	  t->sp[(48+ 0)/8] = (unsigned long)_thrstart; }
 #elif mips
 	{ extern void _start(void);
 	  t->sp -= 16/4;
@@ -269,7 +269,7 @@
 	  	*--t->sp = (unsigned long)_start - 8;
 	  	*--t->sp = (unsigned long)fp;
 	  	t->sp -= 64/4; }
-#elif linux && i386
+#elif (linux || unix) && i386
 	{ extern void _thrstart(void);
 	  t->sp -= 4/4;
 	  *t->sp = (unsigned long)_thrstart;
