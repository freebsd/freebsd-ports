--- InterBase.xs.orig	Fri Mar 26 17:19:34 2004
+++ InterBase.xs	Fri Mar 26 17:21:26 2004
@@ -22,11 +22,13 @@
     PERL_SET_CONTEXT(ev->dbh->context);
     {
 #else
+#if defined(PERL_GET_CONTEXT)
     void *context = PERL_GET_CONTEXT;
     PerlInterpreter *cb_perl = perl_alloc();
     PERL_SET_CONTEXT(cb_perl);
     {
 #endif
+#endif
         dSP;
         char ISC_FAR *result = ev->result_buffer;
 
@@ -52,9 +54,11 @@
     /* restore old context*/
     PERL_SET_CONTEXT(context);
 #else
+#if defined(PERL_GET_CONTEXT)
     }
     PERL_SET_CONTEXT(context);
     perl_free(cb_perl);
+#endif
 #endif
 
     return (0);
