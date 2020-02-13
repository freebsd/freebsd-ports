--- libguile/__scm.h.orig	2010-12-13 17:25:01 UTC
+++ libguile/__scm.h
@@ -434,7 +434,8 @@
  * that all the state of the process is contained in the stack.
  */
 
-#if defined (sparc) || defined (__sparc__) || defined (__sparc)
+#if (defined (sparc) || defined (__sparc__) || defined (__sparc)) && \
+    (!defined(__FreeBSD__))
 # define SCM_FLUSH_REGISTER_WINDOWS asm("ta 3")
 #else
 # define SCM_FLUSH_REGISTER_WINDOWS /* empty */
