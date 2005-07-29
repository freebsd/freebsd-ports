--- i386_dep.c.orig	Sun Jun 12 14:32:11 2005
+++ i386_dep.c	Sun Jun 12 14:45:17 2005
@@ -473,9 +473,14 @@
   else
   {
      signal(SIGSEGV,SIG_DFL);
+#ifdef FREEBSD
+     fprintf(stderr,"catchSEGV; &context = %p, in_run_time_system=%i, context.trapno=%ld\n",
+             scp, in_run_time_system, scp->sc_trapno);
+#else
      fprintf(stderr,"catchSEGV; &context = %p, in_run_time_system=%i, context.trapno=%ld\n",
              &context, in_run_time_system, context.trapno);
      signal(SIGSEGV,catchSEGV);
+#endif
   }
 #endif
 
