--- libguile/__scm.h.orig	2014-01-21 21:25:11 UTC
+++ libguile/__scm.h
@@ -544,7 +544,8 @@ typedef void *scm_t_subr;
  * that all the state of the process is contained in the stack.
  */
 
-#if defined (sparc) || defined (__sparc__) || defined (__sparc)
+#if (defined (sparc) || defined (__sparc__) || defined (__sparc)) && \
+	    defined(__FreeBSD__)
 # define SCM_FLUSH_REGISTER_WINDOWS asm("ta 3")
 #else
 # define SCM_FLUSH_REGISTER_WINDOWS /* empty */
