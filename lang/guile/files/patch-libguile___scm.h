--- libguile/__scm.h.orig	Sat Apr 12 14:16:08 2003
+++ libguile/__scm.h	Sun Jun  1 16:32:36 2003
@@ -354,7 +354,8 @@
  * that all the state of the process is contained in the stack. 
  */
 
-#if defined (sparc) || defined (__sparc__) || defined (__sparc)
+#if (defined (sparc) || defined (__sparc__) || defined (__sparc)) && \
+    (!defined(__FreeBSD__))
 # define SCM_FLUSH_REGISTER_WINDOWS asm("ta 3")
 #else
 # define SCM_FLUSH_REGISTER_WINDOWS /* empty */
