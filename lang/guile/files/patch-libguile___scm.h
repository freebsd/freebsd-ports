--- libguile/__scm.h	2008-02-23 18:14:28.106264450 -0600
+++ libguile/__scm.h	2008-02-23 18:15:41.306005478 -0600
@@ -411,7 +411,8 @@
  * that all the state of the process is contained in the stack.
  */
 
-#if defined (sparc) || defined (__sparc__) || defined (__sparc)
+#if (defined (sparc) || defined (__sparc__) || defined (__sparc)) && \
+    (!defined(__FreeBSD__))
 # define SCM_FLUSH_REGISTER_WINDOWS asm("ta 3")
 #else
 # define SCM_FLUSH_REGISTER_WINDOWS /* empty */
