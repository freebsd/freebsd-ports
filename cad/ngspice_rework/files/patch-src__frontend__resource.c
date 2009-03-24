--- src/frontend/resource.c.orig	2008-11-19 14:45:28.000000000 -0500
+++ src/frontend/resource.c	2008-12-29 15:44:52.000000000 -0500
@@ -605,6 +605,7 @@
 fault(void)
 {
     signal(SIGSEGV, (SIGNAL_FUNCTION) fault);	/* SysV style */
+    signal(SIGBUS, (SIGNAL_FUNCTION) fault);	/* SysV style */
     LONGJMP(env, 1);
 }
 
